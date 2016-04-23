/*************************************************************************
        > File Name: hdu_1042_大数阶乘.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月20日 星期三 21时30分05秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 50086;
int a[N];

int main()
{
	int n;
	while(cin>>n)
	{
		memset(a, 0, sizeof(a));
		if(n == 0 || n == 1)
		{
			printf("1\n");
			continue;
		}
		int len = 1;
		a[0] = 1;
		for(int i = 2; i <= n; i++)
		{
			for(int j = 0; j < len; j++)
			{
				a[j] *= i;
			}
			for(int j = 0; j < len; j++)
			{
				if(a[j] > 9)
				{
					a[j+1] += a[j] / 10;
					a[j] %= 10;
					if(j == len-1) len++;
				}
			}
		}
		for(int i = len-1; i >= 0; i--) printf("%d", a[i]);
		printf("\n");
	}

    return 0;
}
