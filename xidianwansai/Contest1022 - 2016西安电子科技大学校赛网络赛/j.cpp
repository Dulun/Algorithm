/*************************************************************************
        > File Name: j.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月21日 星期四 19时59分17秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 1e5+9;

struct Node
{
	int l, r;
	int k, left;
};

int n, s;
Node a[N];
int sum[N] = {0};
int ans[N] = {0};
bool over = 0;

void dfs(int cur, int left)
{
	if(cur == n+1)
	{
		if(left == 0)
		{
			over = 1;
			for(int i = 1; i < cur-1; i++)
				printf("%d ", ans[i]);
			printf("%d\n", ans[n]);
		}
		return;
	}

	if(sum[n] - sum[cur-1] < left) return;
	if(sum[n] - sum[cur-1] == left)
	{
		over = 1;
		for(int i = 1; i < cur; i++) printf("%d ", ans[i]);
		for(int i = cur; i < n; i++) printf("%d ", a[i].r);
		printf("%d\n", a[n].r);
		return ;
	}

	for(int i = a[cur].l; i <= a[cur].r; i++)
	{
		if(over) return ;
		if(left >= i)
		{
			ans[cur] = i;
			dfs(cur+1, left - i);
		}
	}
	return;
}

int main()
{
	while(~scanf("%d%d", &n, &s))
	{
		over = 0;
		sum[0] = 0;

		for(int i = 1; i <= n; i++)
		{
			scanf("%d%d", &a[i].l, &a[i].r);
			sum[i] = sum[i-1] + a[i].r;
		}
		if(sum[n] < s) printf("Xue Beng\n");
		if(sum[n] == s)
		{
			for(int i = 1; i < n; i++)
			{
				printf("%d ", a[i].r);
			}
			printf("%d\n", a[n].r);
			continue;
		}
		dfs(1, s);
	}

    return 0;
}
