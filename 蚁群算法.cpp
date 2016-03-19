#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <cctype>
#include <limits.h>
#include <time.h>
#include <stdlib.h>
/*
pow函数很慢，所以需要注意如何进行修改
*/
using namespace std;
#define EDGE_MAX 4801
#define CITY_MAX 601
#define CHOOSED_CITY 51
#define N_MAX 10000000
#define DEBUG
struct Edge {
	int u;//起点
	int v;//终点
	int w;//权重
	int next;//下一跳边标号
};
Edge edge[EDGE_MAX];//边
int pre[EDGE_MAX];//邻接表头
int check_point[CHOOSED_CITY];//输入的，检查点
int check_point_weight;/************需要求改,设置一个新权重************/
bool is_died_point[CITY_MAX];
bool is_check[CHOOSED_CITY];//是否check点
int edge_num;//边数
int vertex_num;//定点数
int start_point, end_point, check_point_num;//起点终点
bool flag;

const double ALPHA = 1.0; //启发因子
const double BETA = 2.0;  //期望因子
const double ROU = 0.5;   //信息素残留

const int N_ANT_COUNT = 40; //蚂蚁数量
const int N_IT_COUNT = 100; //迭代次数
const int N_CITY_COUNT = CITY_MAX;//城市数量

const double DBQ = 100.0;     //总共信息素
const double DB_MAX = 1e9;    //一个标志数,10的9次方

double g_Trial[CITY_MAX][CITY_MAX];//两两城市间的信息素
int g_Distance[CITY_MAX][CITY_MAX];//城市之间的距离

int rnd(int nLow, int nUpper) {
	return nLow + (nUpper - nLow)* rand() / (RAND_MAX + 1);
}
double rnd(double dbLow, double dbUpper) {
	double dbTemp = rand() / ((double)RAND_MAX + 1.0);
	return dbLow + dbTemp * (dbUpper - dbLow);
}

double ROUND(double dbA) {
	return (double)((int)dbA + 0.5);
}
class CAnt {
public:
	CAnt();
	~CAnt();
public:
	int m_nPath[CITY_MAX];//蚂蚁走过的路径
	int m_nPathLength;
	int m_nAllowedCity[CITY_MAX];//去过的城市
	int m_nCheckedCity[CITY_MAX];//选择的城市
	int m_nCheckedCityCount;//去过选择的城市的数量
	int m_nCurCityNo;//当前城市
	int m_nMovedCityCount;//去过的城市数量
public:
	int ChooseNextCity();
	void Init();
	bool Move();
	void Search();
	int CalPathLength();
};

CAnt::CAnt() {}
CAnt::~CAnt() {}
void CAnt::Init() {//蚂蚁的初始化
	memset(m_nCheckedCity, 0, sizeof(m_nCheckedCity));//设置检查的城市
	memset(m_nPath, -1, sizeof(m_nPath));//设置path为-1
	for (int i = 0; i < N_CITY_COUNT; i++)
	{
		m_nAllowedCity[i] = 1;//所有城市都没有被访问过
	}
	m_nPathLength = 0;//长度为0
	m_nCurCityNo = start_point;
	m_nPath[0] = m_nCurCityNo;
	m_nMovedCityCount = 0;//都是从0开始
	m_nCheckedCityCount = 0;
	m_nMovedCityCount++;//去过的城市+1
}

bool CAnt::Move() {
	int nCityNo = ChooseNextCity();
	m_nPath[m_nMovedCityCount] = nCityNo;
	m_nAllowedCity[nCityNo] = 0;//设置这个城市已经去过了
	m_nCurCityNo = nCityNo;
	m_nMovedCityCount++;
	if (is_check[nCityNo])
		m_nCheckedCityCount++;
	if (nCityNo == -1)
		return false;
	else
		return true;
}
int CAnt::ChooseNextCity() 
{
	int nSelectedCity = -1;
	double dbTotal = 0.0;
	double prob[CITY_MAX];//保存各个城市被选中的概率

	memset(prob, 0.0, sizeof(prob));

	int nCityNum = 0;
	for (int i = pre[m_nCurCityNo]; i != -1; i = edge[i].next)
	{

		if (m_nAllowedCity[edge[i].v] == 1)//城市没有去过
		{
			if (edge[i].v == end_point)
			{
				if (m_nCheckedCityCount != check_point_num) 
				{
					prob[edge[i].v] = 0.0;//如果所有检查点都没有走完，不能选择最后一点
					continue;
				}
			}
			prob[edge[i].v] = pow(g_Trial[m_nCurCityNo][edge[i].v], BETA)*pow(1.0 / edge[i].w, ALPHA);
			dbTotal += prob[edge[i].v];
			nCityNum++;
		}
		else
		{
			prob[edge[i].v] = 0.0;
		}
	}
	//进行转盘选择
	if (nCityNum == 0)
		return -1;//表示这只蚂蚁没有路可以走，直接让这只蚂蚁去死
	double dbTemp = dbTotal;
	/*
	浮点判断都需要修改
	*/
	if (dbTemp > 0.0)
	{
		dbTemp = rnd(0.0, dbTotal);
		for (int i = pre[m_nCurCityNo]; i != -1; i = edge[i].next)
		{
			if (m_nAllowedCity[edge[i].v] == 1)//如果该点没有被访问
			{
				dbTemp = dbTemp - prob[edge[i].v];
				if (dbTemp < 0.0)//如果小于零，那么认为这只蚂蚁可以选择该点
				{
					if (edge[i].v == end_point)//如果选择的是最后一个点
					{
						if (m_nCheckedCityCount == check_point_num) {
							nSelectedCity = edge[i].v;
							break;
						}
						else                   
							continue;
					}
					else
					{
						nSelectedCity = edge[i].v;
						break;
					}
				}
			}
		}
	}
	//所有的检查点选择了，才能选择end_point，如果上面没有选到
	if (nSelectedCity == -1)
	{
		for (int i = pre[m_nCurCityNo]; i != -1; i = edge[i].next)
		{
			if (m_nAllowedCity[edge[i].v] == 1)
			{
				if (edge[i].v == end_point)//如果是最后一个点
				{
					if (m_nCheckedCityCount == check_point_num)
					{
						nSelectedCity = edge[i].v;
						break;
					}
				}
				else
				{
					nSelectedCity = edge[i].v;//选择其他的点
					break;
				}
			}
		}
	}
	return nSelectedCity;
}


void CAnt::Search() {
	Init();
	bool flag = true;
	do
	{
		flag = Move();
	} while (flag && m_nAllowedCity[end_point] == 1);
	if(flag == false)
		m_nPathLength = N_MAX;
	else if(m_nCheckedCity[end_point] == 0)
		CalPathLength();
}

int CAnt::CalPathLength() {
	m_nPathLength = 0;
	int m = 0;
	int n = 0;
	for (int i = 1; i < m_nMovedCityCount; i++)
	{
		m = m_nPath[i];
		n = m_nPath[i - 1];
		m_nPathLength += g_Distance[n][m];
	}
	return m_nPathLength;
}

class CTsp {
public:
	CAnt m_cAntAry[N_ANT_COUNT];
	CAnt m_cBestAnt;//保存最优解
public:
	void InitData();
	void Search();
	void UpdateTrial();
};
void CTsp::InitData() {
	m_cBestAnt.m_nPathLength = N_MAX;
	//int nTemp = 0;
	for (int i = 0; i < vertex_num; i++)
	{
		for (int j = 0; j < vertex_num; j++)
		{
			g_Distance[i][j] = N_MAX;
			g_Trial[i][j] = 0.0;//初始信息素设置为0
		}
	}
	for (int i = 0; i < edge_num; i++)//设置路径
	{
		if (g_Distance[edge[i].u][edge[i].v] > edge[i].w)
		{
			g_Distance[edge[i].u][edge[i].v] = edge[i].w;
			g_Trial[edge[i].u][edge[i].v] = 1.0;
		}
	}

}
void CTsp::Search() 
{
	//char cBuf[256];
	//
	int n_it_count = 0;
	while (n_it_count < N_IT_COUNT)
	{
		for (int j = 0; j < N_ANT_COUNT; j++)
		{
			m_cAntAry[j].Search();// 每一只蚂蚁进行搜索
			if (m_cAntAry[j].m_nPathLength == N_MAX)
			{
				continue;
			}
		}
		for(int j = 0; j < N_ANT_COUNT; j++)
		{
			if (m_cAntAry[j].m_nPathLength < m_cBestAnt.m_nPathLength)
			{
				m_cBestAnt = m_cAntAry[j];
			}
		}
		UpdateTrial();
		n_it_count++;
	}
}
double dbTempAry[N_CITY_COUNT][N_CITY_COUNT];	//临时数组，
void CTsp::UpdateTrial() {
	memset(dbTempAry, 0, sizeof(dbTempAry));
	int m = 0;
	int n = 0;
	for (int i = 0; i < edge_num; i++)
	{
		m = edge[i].u;
		n = edge[i].v;
		for (int j = 0; j < N_ANT_COUNT; j++)
		{
			dbTempAry[m][n] = dbTempAry[m][n] + DBQ / m_cAntAry[j].m_nPathLength;//信息素的计算需要数学理论推导
		}
	}
	for (int i = 0;i<N_CITY_COUNT;i++)
	{
		for (int j = 0;j<N_CITY_COUNT;j++)
		{
			g_Trial[i][j] = g_Trial[i][j] * ROU + dbTempAry[i][j]; //最新的环境信息素 = 留存的信息素 + 新留下的信息素
		}
	}
	//更新环境信息素
}

int main() {
	cin >> edge_num >> vertex_num;
	int u, v, w;
	memset(pre, -1, sizeof(pre));
	memset(is_check, false, sizeof(is_check));
	for (int i = 0; i < edge_num; i++)
	{
		cin >> u >> v >> w;
		edge[i].u = u;
		edge[i].v = v;
		edge[i].w = w;
		edge[i].next = pre[u];
		pre[u] = i;
	}
	cin >> start_point >> end_point >> check_point_num;
	for (int i = 0; i < check_point_num; i++)
	{
		cin >> check_point[i];
		is_check[check_point[i]] = true;
	}

	CTsp tsp;
	tsp.InitData();

	tsp.Search();
	
	if (tsp.m_cBestAnt.m_nPathLength == N_MAX)
		cout << "NA" << endl;
	else {
		cout <<"Length:"<< tsp.m_cBestAnt.m_nPathLength << endl;
		cout << "Through points:" << endl;
		for (int i = 0; i < tsp.m_cBestAnt.m_nMovedCityCount; i++)
		{
			cout << tsp.m_cBestAnt.m_nPath[i] << " ";
		}
	}
	puts("");
	return 0;
}

/*
7 4
0 1 1 
0 2 2
0 3 1 
2 1 3
3 1 1 
2 3 1
3 2 1
0 1 2 
2 3 



45 20
0 13 15
0 8 17
0 19 1
0 4 8
1 0 4
2 9 19
2 15 8
3 0 14
3 11 12
4 1 15
4 5 17
5 8 18
5 9 14
5 6 2
6 17 4
7 13 1
7 16 9
8 6 1
8 12 17
9 14 11
10 12 1
11 7 12
11 4 7
12 14 5
13 17 12
13 4 2
14 19 9
15 10 14
15 18 2
16 8 1
17 9 14
17 19 3
17 18 10
18 15 8
18 3 8
19 18 12
2 3 20
3 5 20
5 7 20
7 11 20
11 13 20
17 11 20
11 19 20
17 5 20
5 19 20
2 19 6
3 5 7 11 13 17
*/

