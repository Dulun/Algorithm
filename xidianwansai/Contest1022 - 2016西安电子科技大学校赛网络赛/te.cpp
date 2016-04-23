/*************************************************************************
        > File Name: te.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月21日 星期四 22时51分56秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 1006;
int W[N], V[N];
int dp[N*50];

int main()
{
	int n, w;
	while(~scanf("%d%d", &n, &w))
	{
		int sum = 0;
		for(int i=0; i<n; i++)
		{
			scanf("%d%d", &W[i], &V[i]);
			sum += V[i];
		}
		memset(dp, 0x3f, sizeof(dp));
		dp[0] = 0;
		for(int i=0; i<n; i++)
			for(int j=sum; j>=V[i]; j--)
				dp[j] = min(dp[j-V[i]]+W[i], dp[j]);

		for(int i=sum; i>=0; i--)
			if(dp[i] <= w)
			{
				printf("%d\n", i);
				break;
			}
	}
    return 0;
}
