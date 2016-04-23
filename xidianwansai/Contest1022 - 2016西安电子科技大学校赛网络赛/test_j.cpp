/*************************************************************************
        > File Name: test_j.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月22日 星期五 10时44分47秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 1000086;
struct Node{
	int l, r;
	int use;
};
Node a[N];
int ans_t[N];
int n, s;

void _sovel(int sum_cur, int k)
{
	for(int i = a[k].use; i < a[k].r; i++)
	{
		if(sum_cur == s) break;
		sum_cur += 1;
		a[k].use++;
	}

	for(int i = 1; i <n ;i++)
	{
		printf("%d ", a[i].use);
	}
	printf("%d\n",a[n].use);
}

void sovle_a(int cur)
{
	for(int i = n; ; i--)
	{
		if(cur + a[i].r - a[i].use >= s)
		{
			_sovel(cur, i);
			return;
		}
		else{
			cur += (a[i].r - a[i].use);
			a[i].use = a[i].r;
		}

	}
}

int main()
{
	while(~scanf("%d%d", &n, &s))
	{
		int k = 0;
		int q = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d%d", &a[i].l, &a[i].r);
			a[i].use = a[i].l;
			q += a[i].l;
			k += a[i].r;
		}
		if(k < s || q > s)
		{
			printf("Xue Beng\n");
			continue;
		}
		if(k == s)
		{
			for(int i = 1; i < n; i++)
			{
				printf("%d ", a[i].r);
			}
			printf("%d\n", a[n].r);
			continue;
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			ans += a[i].use;
		}
		sovle_a(ans);
	}
    return 0;
}
