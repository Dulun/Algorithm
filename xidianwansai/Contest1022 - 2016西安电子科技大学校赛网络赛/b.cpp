/*************************************************************************
        > File Name: b.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月20日 星期三 12时02分19秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
const int N = 100;

LL sum[N];

void init()
{
	sum[0] = 0;
	sum[1] = 1;
	sum[2] = 1;
	for(int i = 3; i < N; i++)
	{
		sum[i] = sum[i-1] + sum[i-2];
	}
}

int main()
{
	init();
	LL n;
	while(~scanf("%lld", &n))
	{
		if(n == 3 || n == 2 || n == 1)
		{
			printf("1 1\n");
			continue;
		}
		LL t = n, left, ans, left_pre;
		for(int i = 1; i < N; i++)
		{
			if(t > sum[i])
			{
				t-=sum[i];
				continue;
			}
			else{
				left = t;
				left_pre = sum[i-1];
				ans = i;
				break;
			}
		}
		if(left > left_pre)
		{
			printf("%lld %lld\n", ans, left);
		}
		else{
			printf("%lld %lld\n", ans - 1, left_pre);
		}
	}
    return 0;
}
