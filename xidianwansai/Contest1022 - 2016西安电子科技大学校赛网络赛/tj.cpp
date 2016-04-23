/*************************************************************************
        > File Name: tj.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月21日 星期四 23时27分07秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 100086;
int l[N], r[N];
int ans[N];
int n, s;
bool flag;
int p[N],q[N];
bool z[][];

void dfs(int k, int sum)
{
	if(k > n)
	{
		if(sum == 0)
		{
			for(int i=1; i<k; i++)
				printf("%d ", ans[i]);
			printf("\n");
			flag = 1;
		}
		return;
	}
	if(flag || sum < p[n]-p[k-1] || sum > q[n]-q[k-1])
		return;
	for(int i=l[k]; i<=r[k]; i++)
	{
		ans[k] = i;
		dfs(k+1, sum-i);
	}
}

int main()
{
	while(~scanf("%d%d", &n, &s))
	{
		flag = 0;
		p[0] = q[0] = 0;
		for(int i=1; i<=n; i++)
		{
			scanf("%d%d", &l[i], &r[i]);
			p[i] = p[i-1]+l[i], q[i] = q[i-1]+r[i];
		}
		dfs(1, s);
		if(!flag)
			printf("Xue Beng\n");
	}
    return 0;
}
