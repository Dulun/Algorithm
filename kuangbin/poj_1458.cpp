/*************************************************************************
        > File Name: poj_1458.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月19日 星期二 16时48分16秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 666;
char a[N];
char b[N];
int dp[N][N];

int main()
{
	while(~scanf("%s%s", a+1, b+1))
	{
		int ans = 0;
		int len_a = strlen(a+1);
		int len_b = strlen(b+1);
		memset(dp, 0, sizeof(dp));

		for(int i = 1; i <= len_a; i++)
		{
			for(int j = 1; j <= len_b; j++)
			{
				if(a[i] != b[j] )
				{
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
				else{
					dp[i][j] = dp[i-1][j-1]+1;
				}
				ans = max(ans, dp[i][j]);
			}
		}
		printf("%d\n", ans);
	}
    return 0;
}
