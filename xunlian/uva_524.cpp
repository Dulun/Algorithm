/*************************************************************************
        > File Name: uva_524.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月14日 星期四 11时23分52秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 50086;
int n;
bool v[20];
int a[20];

bool check(int k)
{
	if(k == 0 || k == 1) return false;
	if(k == 2 || k == 3) return true;

	for(int i = 2; i*i <= k; i++)
	{
		if(k % i == 0) return false;
	}
	return true;
}

void dfs(int cur)
{
	if(cur == n+1)
	{
		if(check(1 + a[n]))
		{
			for(int i = 1; i < n; i++) printf("%d ", a[i]);
			printf("%d\n", a[n]);
		}
		return ;
	}

	for(int i = 1; i <= n; i++)
	{
		if(!v[i] && check(a[cur-1]+i))
		{
			v[i] = true;
			a[cur] = i;
			dfs(cur+1);
			v[i] = false;
		}
	}
}

void init()
{
	memset(a, 0, sizeof(a));
	memset(v, 0, sizeof(v));
	v[0] = true;
	v[1] = true;
	a[0] = 0;
	a[1] = 1;
}

int main()
{
	int cnt = 0;
	bool flag = 0;
	while(~scanf("%d", &n))
	{
		if(flag == 1)
			printf("\n");
		flag = 1;
		//printf("%d\n", check(n));
		init();
		printf("Case %d:\n", ++cnt);
		dfs(2);
	}

    return 0;
}
