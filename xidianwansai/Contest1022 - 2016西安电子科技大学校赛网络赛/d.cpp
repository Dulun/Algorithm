/*************************************************************************
        > File Name: d.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月20日 星期三 14时19分02秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 50086;

int main()
{
	int x, y, a;
	while(~scanf("%d%d%d", &x, &y, &a))
	{
		int k = x+y;
		a %= k;
		if(a != 0 && x >= a)
			printf("wanshen\n");
		else printf("light\n");
	}
    return 0;
}
