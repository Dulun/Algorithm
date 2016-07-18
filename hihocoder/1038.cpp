/*************************************************************************
        > File Name: 1038.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年07月18日 星期一 20时06分16秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 1e5+9;

int dp[N];
int p[N];
int w[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d", &w[i], &p[i]);
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = m; j >= w[i]; j--)
        {
            if(dp[j-w[i]] + p[i] > dp[j])
            {
                dp[j] = dp[j - w[i]] + p[i];
            }
        }
    }

    printf("%d\n", dp[m]);

    return 0;
}
