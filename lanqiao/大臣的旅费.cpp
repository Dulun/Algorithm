/*************************************************************************
	> File Name: 大臣的旅费.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月16日 星期三 14时03分12秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#define LL long long
using namespace std;
 
const int N = 20086;
int maxcount = 0;
bool visit[N];
int map[N][N];
int num;

LL getcost(int n)
{
    LL sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += 10 + i;
    }
    return  sum;
}


void dfs(int n, int c)
{
    if(c > maxcount) maxcount = c;

    for(int i = 1; i <= num; i++)
    {
        if(!visit[i] && map[n][i])
        {
            visit[i] = 1;
            dfs(i, c+map[n][i]);
            visit[i] = 0;
        }
    }
}

int main()
{
    scanf("%d", &num);
    memset(map, 0, sizeof(map));

    for(int i = 1; i < num; i++) 
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        map[a][b] = c;
        map[b][a] = c;
    }

    for(int i = 1; i <= num; i++)
    {
        memset(visit, 0, sizeof(visit));
        visit[i] = 1;
        dfs(i, 0);
    }
    printf("%d\n",(maxcount+1)*maxcount / 2 + maxcount*10);
 
    return 0;
}

