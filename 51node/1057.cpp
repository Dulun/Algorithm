/*************************************************************************
	> File Name: 1057.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年04月01日 星期五 18时03分45秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
#define mod 100000000000000;
const int N = 1000086;
LL a[N];

int main()
{
    int n;
	while(~scanf("%d", &n))
	{
		memset(a, 0, sizeof(a));
		LL l = 0;
		a[0] = 1;

		for(int i = 1; i <= n; i++)
		{
			LL c = 0;
			for(int j = 0; j <= l; j++)
			{
				LL t = a[j] * i + c;
				a[j] = t % mod;
				c = t / mod;
			}
			if(c != 0)
			{
				l++;
				a[l] = c;
			}
		}
		printf("%lld", a[l]);

		for(int i = l-1; i >= 0; i--)
		{
			printf("%014lld\n", a[i]);
		}
	}
    return 0;
}
