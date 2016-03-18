/*************************************************************************
	> File Name: 1789.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年01月26日 星期二 11时15分18秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

const int inf = 10;
const int large = 2001;

int n;
char str[large][8];
int dist[large][large] = {0};

int weight(int i, int j)
{
    int w = 0; 
    for(int k=0; i<7; k++)
    {
        if(str[i][k] != str[j][k]) w++;
    }
    return w;
}

int prim()
{
    bool visit[large];
    int prim_w = 0;
    int min_w;
    int k, t = n;
    int low[large];

    memset(visit, false, sizeof(u));
    visit[s] = true;
    for(int i = 0; i < n; i++)
    {
        low[i] = inf;
    }

    while(t--)
    {
        for(int i = 0; i < n; i++)
        {
            min_w = inf;
            if(!visit[i] && low[i] > min_w )
                k = i, min_w = low[i];
        }
        visit[k] = true;
        
    }
}
