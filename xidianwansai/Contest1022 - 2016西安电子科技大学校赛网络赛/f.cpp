/*************************************************************************
        > File Name: f.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月20日 星期三 14时45分24秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 50086;
int ans = 0;
bool over = 0;
int a[10];
int now[10];
bool v[10];
int gcd(int a, int b)
{
	return a%b==0 ? b : gcd(b, a%b);
}

bool check(int cur, int k)
{
	if(cur == 0)
		 return true;
	if(cur - 3 >= 0)
	{
		if(gcd(now[cur-3], k) != 1) return false;
	}
	if(cur % 3 != 0 )
	{
		if(gcd(now[cur-1], k) != 1) return false;
	}
	return true;
}

void dfs(int cur)
{
	if(cur == 9)
	{
		ans++;
		return;
	}
	for(int i = 0; i < 9; i++)
	{
		if(v[i] == true) continue;
		if(check(cur, a[i]) == true)
		{
			v[i] = 1;
			now[cur] = a[i];
			dfs(cur+1);
			v[i] = 0;
		}
	}
}

int main()
{
	while(~scanf("%d", &a[0]))
	{
		ans = 0;
		for(int i = 1; i < 9; i++)
		{
			scanf("%d", &a[i]);
		}
		dfs(0);
		if(over == 1)
		{
			printf("0\n");
			continue;
		}
		printf("%d\n", ans);
	}
    return 0;
}
