/*************************************************************************
        > File Name: 1051.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月09日 星期六 21时33分19秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 50086;
int total = 100;
int ans = 0;
int a[200];
bool v[N];

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);

		if(m>=n) { printf("100\n"); continue; }
		a[0] = 0, a[n+1] = 101;
		int ans = 0;
		for(int i=0; i<=n; i++)
		{
			if(i+m+1 > n+1) break;
			int p = a[i+m+1] - a[i] - 1;
			if(ans<p) ans = p;
		}
		printf("%d\n", ans);
	}
	return 0;
}
