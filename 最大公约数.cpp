/*************************************************************************
        > File Name: 最大公约数.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月20日 星期三 21时37分30秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 50086;

LL gcd(LL a, LL b)
{
	return a % b == 0 ? b : gcd(b, a%b);
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		LL a, b;
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", gcd(a, b));
	}

    return 0;
}
