/*************************************************************************
  > File Name: tsp_GA.cpp
  > Author: dulun
  > Mail: dulun@xiyoulinux.org
  > Created Time: 2016年06月20日 星期一 12时42分29秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<time.h>
#define LL long long
using namespace std;

const int City_Num = 10;            //城市个数
const int Unit_Num = 100;           //群体规模
const int Gen_Max  = 500;           //最大迭代数
int ps = 10;                        //变异概率

int length_table[10][10] = {

    {0,1,1272,2567,1653,2097,1425,1177,3947,1},

    {1,0,1,2511,1633,2077,1369,1157,3961,1518},

    {1272,1,0,1,380,1490,821,856,3660,385},

    {2567,2511,1,0,1,2335,1562,2165,3995,933},

    {1653,1633,380,1,0,1,1041,1135,3870,456},

    {2097,2077,1490,2335,1,0,1,920,2170,1920},

    {1425,1369,821,1562,1041,1,0,1,4290,626},

    {1177,1157,856,2165,1135,920,1,0,1,1290},

    {3947,3961,3660,3995,3870,2170,4290,1,0,1},

    {1,1518,385,993,456,1920,626,1290,1,0}
};

class Unit
{
public:
    int path[City_Num];
    int length;
};

bool cmp(Unit a, Unit b)
{
    return a.length < b.length;
}

class Group
{
public:
    Unit group[Unit_Num];
    Unit best;
    int best_gen;

    Group()
    {
        best.length = 0x3f3f3f3f;
        best_gen = 0;

        for(int i = 0; i < Unit_Num; i++)
        {
            bool flag[City_Num] = {};
            for(int j = 0; j < City_Num; j++)
            {
                int t_city = rand() % City_Num;     //随机一个城市
                while(flag[t_city])                 //如果访问过，次随机
                {
                    t_city = rand() % City_Num;
                }
                flag[t_city] = true;                //直到找到一个没有访问过的
                group[i].path[j] = t_city;
            }
        }
    }

    void Assess() //评估
    {
        for(int k = 0; k < Unit_Num; k++)
        {
            int rel = 0;
            for(int i = 1; i < City_Num; i++)
            {
                rel += length_table[group[k].path[i-1]][group[k].path[i]];
            }
            rel += length_table[group[k].path[City_Num-1]][group[k].path[0]];
            group[k].length = rel;
        }
    }

    void Unit_Sort()
    {
        sort(group, group + Unit_Num, cmp);
    }

    Unit Cross(Unit & father, Unit & mother)
    {
        int l = rand() % City_Num;
        int r = rand() % City_Num;
        if(l > r)
        {
            swap(l, r);
        }

        bool flag[City_Num] = {};
        for(int i = l; i <= r; i++)
        {
            flag[father.path[i]] = true;
        }
        Unit son;
        int pos = 0;

        for(int i = 0; i < l; i++)
        {
            while(flag[mother.path[pos]])
            {
                pos++;
            }
            son.path[i] = mother.path[pos++];
        }

        for(int i = l; i <= r; i++)
        {
            son.path[i] = father.path[i];
        }

        for(int i = r+1; i < City_Num; i++)
        {
            while(flag[mother.path[pos]])
            {
                pos++;
            }
            son.path[i] = mother.path[pos++]; //123412341234123412412
        }
        return son;
    }

    void Mutation(Unit &t) //突变
    {
        int proport = rand() % 100;

        if(proport > ps)
        {
            return;
        }
        int one = rand() % City_Num;
        int two = rand() % City_Num;
        while(two != one)
        {
            two = rand() % City_Num;
        }
        swap(t.path[one], t.path[two]);
    }

    void Work()     //进化
    {
        for(int i = 0; i < Gen_Max; i++)
        {
            if(i > 20) // 如果进化层数大于20,加大变异概率
            {
                ps *= 3;
            }

            Assess();       //评估
            Unit_Sort();    //排序

            if(best.length > group[0].length)
            {
                memcpy(&best, &group[0], sizeof(group[0]));
                best_gen = i;
            }
            for(int j = 0; j + 2 < Unit_Num; j += 3)
            {
                group[j+2] = Cross(group[j], group[j+1]); //交叉
            }

            for(int j = 0; j < City_Num; j++)
            {
                Mutation(group[j]);                       //变异
            }
        }
    }

    void Print()    //输出
    {
        for(int i = 0; i < Unit_Num; i++)
        {
            printf("No.%d path info: ", i);
            for(int j = 0; j < City_Num; j++)
            {
                printf("%d ", group[i].path[j]);
            }
            printf("; All sum = %d \n", group[i].length);
        }
    }
};

Unit group[Unit_Num];
Unit besttone;
int Generation_Num;


int main()
{
    srand( (int)time(0) );

    for(int i = 0; i < 20; i++)
    {
        Group g;
        g.Work();
        g.Print();
        printf("%d \n", g.best.length);
    }

    return 0;
}
