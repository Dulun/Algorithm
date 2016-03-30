/*************************************************************************
	> File Name: hdu_3038.cpp
    	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月28日 星期一 22时03分52秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 500086;

int p[N];
int sum[N];

int find(int x)
{
    if(p[x] != x)
    {
        int f = p[x];
        p[x] = find(p[x]);
        sum[x] += sum[f];
    }
    return p[x];
}

void init(int n)
{
    for(int i = 0; i <= n; i++)
    {
        p[i] = i;
        sum[i] = 0;
    }
}

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        init(n);
        int ans = 0;
        int a, b, v;
        while(m--)
        {
            scanf("%d%d%d", &a, &b, &v);
            a-=1;
            int x = find(a);
            int y = find(b);
            if(x != y)
            {
                p[x] = y;
                sum[x] = sum[b] - sum[a] + v;
            }
            else 
            {
                if(sum[a] - sum[b] != v) ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
