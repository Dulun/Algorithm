/*************************************************************************
        > File Name: 1078_t.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年05月14日 星期六 20时18分50秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 586;
int a[N][N];
bool v[N];
int d[N];
int n;
int prim()
{
    memset(v, false, sizeof(v));
    memset(d, 0x3f3f3f3f, sizeof(d));
    int ans = 0;
    int k = 0, min = 0x3f3f3f3f;
    v[0] = true;
    for(int i = 1; i < n; i++) // 控制，一共找n-1条边
    {
        for(int j = 0; j < n; j++) //更新与k点相连的边
            if(!v[j] && d[j] > a[j][k])
                d[j] = a[j][k];
        for(int j = 0; j < n; j++) //找当前预备点中离组织最近的一条边
            if(!v[j] && d[j] < min) 
                min = d[k=j];
        v[k] = 1;
        ans += min;
        min = 0x3f3f3f3f;
    }
    return ans;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("%d\n", prim());
 
    return 0;
}
