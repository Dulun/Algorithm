/*************************************************************************
        > File Name: hdu_1257.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月19日 星期二 13时11分54秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 1086;

int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		int dp[N], m = 0;
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++)
		{
			int x, j;
			scanf("%d", &x);
			for(j = 1; j <= m; j++)
			{
				if(x <= dp[j])
				{//发现当前系统中存在可以拦截该导弹的最低高度，维护更高的
					//printf("xiaoyu\n");
					dp[j] = x;
					break;
				}
			}
			if(j > m)
			{//没有可以拦截的系统，系统个数加一
				//optprintf("xinzeng!\n");
				dp[++m] = x;
			}
		}
		printf("%d\n", m);
	}
    return 0;
}
