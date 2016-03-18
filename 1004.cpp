/*************************************************************************
	> File Name: 1004.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2015年11月29日 星期日 15时51分58秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<map>
using namespace std;
const int dx[]={1, -1, 0, 0};                 //初始化可移动的方向 
const int dy[]={0, 0, 1, -1};
struct status                               //棋盘状态的信息，包括把16位3进制数转换成一个十进制数的结果hash,移动步数step, 
{                                            //是由谁移动棋子得到此时这个棋盘状态，last=1(黑子方) ， last=2(白子方) 
	int hash, step, last;
	int map[6][6];                        //存储棋盘的状态信息。 
}first;
queue<struct status> Q;                //用BFS，队列 
map<int, bool> h[3]; //哈希查找。 h[1][x]记录黑子方的移动到达的信息，h[1][x]=0，表示还没移动到这个状态，h[1][x]=1，表示之前已经到达过，就不用进队了  
int gethash(status a)                   //把此时棋盘的状态（全部用0,1,2表示没一位的三进制）转换成一个十进制数，用来哈希查找。 
{
	int res = 0;
	int k = 1;
	int i, j;
	for (i = 1; i <= 4; i++)
		for (j = 1; j <= 4; j++)
		{
			res += a.map[i][j] * k;
			k *= 3;
		}
	return res;
}
bool check(status a)       //判断，此时的棋盘状态是否已经是目标状态了。 
{
	int i, j;
	for (i = 1; i <= 4; i++)       //横向连成4个
	{
		bool flag = true;
		for (j = 2; j <= 4; j++)
			if(a.map[i][j-1] != a.map[i][j])
				flag = false;
		if (flag) 
		    return true;
	}
	for (i = 1;i <= 4; i++)      //纵向连成4个
 	{
   		bool flag = true;
		for (j = 2; j <= 4; j++)
			if(a.map[j][i] != a.map[j-1][i])
		flag = false;
		if (flag) 
		    return true;
	}
	if (a.map[1][1] == a.map[2][2])      //对角线 
		if (a.map[2][2] == a.map[3][3])
			if (a.map[3][3] == a.map[4][4])
				return true;
	if (a.map[1][4] == a.map[2][3])      //对角线 
		if (a.map[2][3] == a.map[3][2])
			if (a.map[3][2] == a.map[4][1])
				return true;
	return false;
}
void move(status now, int x, int y, int k)   //移动一步，生成新的棋盘状态，k为移动方向。 
{
	status tmp = now;
	int tmpx = x + dx[k];                     //移动一步，赋值新坐标 
	int tmpy = y + dy[k];
	if (tmpx < 1 || tmpx > 4) return ;         //判断边界，移动一步，过了边界，则此策略不行。 
		if (tmpy < 1 || tmpy > 4) return ;
			if (tmp.map[tmpx][tmpy] == tmp.last)      //有先手后手问题，如果移动的棋子是上次别人的（对方的），比如，白方刚移动完，此时到自己移动一步 
				return ;                              //移动的又恰好是白子，则不行，因为自己不能移动对方的棋子。 
	tmp.last = 3 - tmp.last;                //以上三种移动情况都没问题了，就把移动的新状态 tmp ，重新给last复制,标记为这个状态是自己（黑方）移动的 
	swap(tmp.map[tmpx][tmpy], tmp.map[x][y]);    //空格和 tmp.map[tmpx][tmpy]（黑子或者白子）交换位置。 
	tmp.hash = gethash(tmp);                //移动后的新状态，算出16位三进制数对应的十进制数。 
	tmp.step++;                       	 	//移动成功，步数加一 。 
	if (check(tmp))                    		//如果移动后的新状态恰好是目标状态，则可以输出结果了。 
	{
		printf("%d", tmp.step);
		exit(0);
	}
	if (!h[tmp.last][tmp.hash])   //如果新状态之前没被标记过，则可以入队了。 h[tmp.last][tmp.hash]为移动这步棋的人。生成的新状态是属于他的。 
	{                                              //比如tmp.last=1，表示这个新状态是黑方移动的，相应的去找他对应的哈希状态。 
		h[tmp.last][tmp.hash] = 1;       //入队，重新赋值。表示此状态已经出现过 
		Q.push(tmp);              //入队。 
	} 
}
void bfs()
{
	first.hash = gethash(first);     //首状态对应的十进制数 
	first.last = 1;                  //因为谁先下都行。  所以开始要进队两个元素。 注意 first.last 是不同的。 
	Q.push(first);
	first.last = 2;
	Q.push(first);
	while (!Q.empty())
	{
		status now;
		now	= Q.front();
		Q.pop();
		int x1 = -1, x2 = -1, y1 = -1, y2 = -1;
		int i, j, k;
		for (i = 1; i <= 4; i++)
		 	for (j = 1; j <= 4; j++)            //寻找两个空格的坐标 
				if (!now.map[i][j])
				{
				 	if (x1 == -1 && y1 == -1)         //x1,y1;  x2,y2  分别是两个空格的坐标 
					{
						x1 = i;        
						y1 = j;
					}
					else
					{
						x2 = i;
						y2 = j;
					}
				}
		for (k = 0; k < 4; k++)      //一个棋盘有两个空格，所以两个一起来搜索四个方向。 
		{
			move(now, x1, y1, k);
		 	move(now, x2, y2, k);
		}
	}
}
int main()
{
	int i, j;
  	for (i = 1; i <= 4; i++)
	{
		char s[10];
		scanf("%s", s);
		for (j = 0; j < 4; j++)          //把每一位的棋子换成 0（空格）,1（黑子）,2（白子） （三进制） ，此时棋盘的每个格子都是0,1,2.的数字 
		{                          //这是一个16位的3进制数，对应一个十进制数。然后通过哈希该棋盘的十进制数 就可以找到对应的棋盘状态。 
			if (s[j] == 'B') first.map[i][j+1] = 1;
			if (s[j] == 'W') first.map[i][j+1] = 2;
		}
	}
	bfs();
	return 0;
}

