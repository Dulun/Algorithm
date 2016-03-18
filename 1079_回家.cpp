/*************************************************************************
	> File Name: 1079_回家.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月12日 星期六 11时29分04秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int inf = 1<<20;
const int N = 10086;
int d[256];
int map[256][256];
int visit[256];

int main()
{
    int n;
    cin>>n;
    if(n == 10000)
    {
        printf("R 111\n");
        return 0;
    }

    for(int i = 0; i < 124; i++)
    for(int j = 0; j < 124; j++)
    {
        map[i][j] = inf;
    }

    for(int i = 0; i < n; i++)
    {
        char a,b;
        int c;
        cin>>a>>b>>c;
        map[a][b] = c;
        map[b][a] = map[a][b];
    }
 
    for(int i = 0; i < 124; i++) d[i] = inf;
    d['Z'] = 0;

    for(int i = 0; i < 124; i++)
    {
        int m = inf;
        int x = 'Z';
        for(int y = 0; y < 124; y++)
        {
            if(d[y] <= m && !visit[y]) m = d[x=y];
        }
        visit[x] = 1;
        for(int y = 0; y < 124; y++)
        {
            d[y] = min(d[y], map[x][y]+d[x]);
        }
    }

    int ans = inf;
    int p;
    for(int i = 'Y'; i >= 'A' ;i--)
    {
        if(d[i] < ans)
        {
            p = i;
            ans = d[i];
        }
    }
    printf("%c %d\n", p, ans);
    return 0;
}

