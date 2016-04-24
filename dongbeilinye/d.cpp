/*************************************************************************
        > File Name: d.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月24日 星期日 13时24分11秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 86;
char a[15][N];
char b[15][N];
char t[N];
char s[N];
int ans = 0;
void sovle(char *a, char *b)
{
	int dp[N][N] = {0};
	int ans_t = -1, now;
	int len_a = strlen(a+1);
	int len_b = strlen(b+1);
	for(int i = 1;  i <= len_a; i++)
		for(int j = 1; j <= len_b; j++)
		{
			if(a[i] == b[j])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
			}

			if(dp[i][j] == ans_t)
			{
				int p = now+1-ans_t;
				int q = i+1-ans_t;
				while(a[q] == a[p])
				{
					if(p >=now) break;
					p++;
					q++;
				}
				if(a[q] < a[p]) now = i;
			}

			if(dp[i][j] > ans_t)
			{
				ans_t = dp[i][j];
				now = i;
			}
		}


	int cnt = 1;
	for(int i = now+1-ans_t; i <= now; i++)
	{
		t[cnt++] = a[i];
	}
	t[cnt] = 0;
	ans = strlen(t+1);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		memset(t, 0, sizeof(t));
		ans = 0;
		int n;
		scanf("%d", &n);

		for(int i = 0; i < n; i++)
			scanf("%s", a[i]+1);


		sovle(a[0], a[1]);
		for(int i = 2; i < n; i++)
		{
			sovle(a[i], t);
		}
		if(ans < 3)
			printf("No significant commonalities\n");
		else
			printf("%s\n", t+1);
	}
    return 0;
}
