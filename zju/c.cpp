/*************************************************************************
        > File Name: c.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月23日 星期六 13时12分08秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 50086;
int a[10][10];


void solve()
{
	int k1, k2, k3, k4, k5;
	//1

	if(a[1][1] == 1 || a[1][1] == 2)
	{
		k1 = 2;
		printf("%d %d\n", k1-1, a[1][k1]);
	}
	if(a[1][1] == 3)
	{
		k1 = 4;
		printf("%d %d\n", k1-1, a[1][k1]);
	}
	if(a[1][1] == 4)
	{
		k1 = 5;
		printf("%d %d\n", k1-1, a[1][k1]);
	}

	//2
	if(a[2][1] == 1)
	{
		for(int i = 2; i <= 5; i++)
		{
			if(a[2][i] == 4)
			{
				k2 = i;
				printf("%d %d\n", k2-1, a[2][k2]);
			}
		}
	}
	if(a[2][1] == 2 || a[2][1] == 4)
	{
		k2 = k1;
		printf("%d %d\n", k2-1, a[2][k2]);
	}
	if(a[2][1] == 3)
	{
		k2 = 2;
		printf("%d %d\n",k2-1, a[2][k2]);
	}

	//3
	if(a[3][1] == 1)
	{
		for(int i = 2; i <= 5; i++)
		{
			if(a[3][i] == a[2][k2])
			{
				k3 = i;
				printf("%d %d\n", k3-1, a[3][k3]);
			}
		}
	}
	if(a[3][1] == 2)
	{
		for(int i = 2; i <= 5; i++)
		{
			if(a[3][i] == a[1][k1])
			{
				k3 = i;
				printf("%d %d\n", k3-1, a[3][k3]);
			}
		}
	}
	if(a[3][1] == 3)
	{
		k3 = 3+1;
		printf("%d %d\n", k3-1, a[3][k3]);
	}
	if(a[3][1] == 4)
	{
		for(int i = 2; i <= 5; i++)
		{
			if(a[3][i] == 4)
			{
				k3 = i;
				printf("%d %d\n", k3-1, a[3][k3]);
				break;
			}
		}
	}



	//4
	if(a[4][1] == 1)
	{
		k4 = k1;
		printf("%d %d\n", k4-1, a[4][k4]);
	}
	if(a[4][1] == 2)
	{
		k4 = 2;
		printf("%d %d\n", k4-1, a[4][k4]);
	}
	if(a[4][1] == 3 || a[4][1] == 4);
	{
		k4 = k2;
		printf("%d %d\n", k4-1, a[4][k4]);
	}
	//
	//5

	if(a[5][1] == 1)
	{
		for(int i = 2; i <= 5; i++)
			if(a[5][i] == a[1][k1] )
			{
				k5 = i;
				printf("%d %d\n", k5-1, a[5][k5]);
			}
	}

	if(a[5][1] == 2)
	{
		for(int i = 2; i <= 5; i++)
			if(a[5][i] == a[2][k2] )
			{
				k5 = i;
				printf("%d %d\n", k5-1, a[5][k5]);
			}
	}

	if(a[5][1] == 3)
	{
		for(int i = 2; i <= 5; i++)
			if(a[5][i] == a[4][k4] )
			{
				k5 = i;
				printf("%d %d\n", k5-1, a[5][k5]);
			}
	}

	if(a[5][1] == 4)
	{
		for(int i = 2; i <= 5; i++)
			if(a[5][i] == a[3][k3] )
			{
				k5 = i;
				printf("%d %d\n", k5-1, a[5][k5]);
			}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= 5; i++)
			for(int j = 1; j <= 5; j++)
				scanf("%d", &a[i][j]);
		solve();
	}

    return 0;
}
