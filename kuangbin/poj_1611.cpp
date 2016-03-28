/*************************************************************************
	> File Name: poj_1611.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月28日 星期一 13时38分31秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50086;

int p[N];
int ans = 1;
int son[N];
int find(int x) { return x == p[x]? x : p[x] = find(p[x]); }
void init(int n) 
{ 
    for(int i = 0; i < n; i++)
    {
        p[i] = i;
        son[i] = 1;
    }
}


void inside(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x != y)
    {
        p[y] = x;
        son[x] += son[y];
    }
}

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) && n+m)
    {
        init(n);
        ans = 1;
        int p = -1;
        for(int i = 0; i < m; i++)
        {
            int k, t, x;
            scanf("%d", &k);
            scanf("%d", &t);
            for(int j = 1; j < k; j++)
            {
                scanf("%d", &x);
                inside(t, x);
                //t = x;
            }
        }       
        printf("%d\n", son[find(0)]);
    }
 
    return 0;
}
