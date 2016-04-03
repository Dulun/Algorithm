/*************************************************************************
	> File Name: poj_1258.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年04月03日 星期日 10时26分43秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
const int inf = 1<<30; 
const int N = 506;
int map[N][N];
int d[N];
bool v[N];
int n;

LL prim()
{
    LL ans = 0;
    memset(v, 0, sizeof(v));
    for(int i = 1; i < n; i++) d[i] = map[0][i];
    v[0] = 1;

    for(int i = 1; i < n; i++)
    {
        int min = inf, k;
        for(int j = 0; j < n; j++)
        {
            if(!v[j] && d[j] < min) min = d[k = j];
        }
        v[k] = 1;
        ans+=d[k];
        for(int j = 0; j < n; j++) 
        {
            if(!v[j] && d[j] > map[k][j]) d[j] = map[k][j];
        }
    }
    return ans;
}


int main()
{
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) { scanf("%d", &map[i][j]); d[i] = inf;} 
        printf("%lld\n", prim());
    }
    return 0;
}
