/*************************************************************************
        > File Name: c_t.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月23日 星期六 14时38分22秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 50086;
int a[6][6];

void solve()
{
	int k1, k2, k3, k4, k5;
	//1
	if(a[0][0] == 1 || a[0][0] == 2)
	{
		k1 = 2;
		printf("%d %d\n", k1, a[0][k1]);
	}
	if(a[0][0] == 3)
	{
		k1 = 3;
		printf("%d %d\n", k1, a[0][k1]);
	}
	if(a[0][0] == 1)
	{
		k1 = 4;
		printf("%d %d\n", k1, a[0][k1]);
	}

	if(a[1][0] == 1)
	{
		for(int i = 1; i <= 4; i++)
		{
			if(a[1][i] == 4)
			{
				k2 = 4;
			}
		}
	}
	if(a[1][0] == 2 || a[1][0] == 4)
	{
		k2 = k1;
	}
	if(a[1][0] == 3)
	{
		k2 = 1;
	}
	printf("%d %d\n", k2, a[2][k2]);


//3----------------------------------
	if(a[2][0] == 1)
	{
		for(int i = 1; i <= 4; i++)
		{
			if(a[2][i] == a[1][k2])
			{
				k3 = i;
			}
		}
	}
	if(a[2][0] == 2)
	{
		for(int i = 1; i <= 4; i++)
		{
			if(a[2][i] == a[0][k1])
			{
				k3 = i;
			}
		}
	}
	if(a[2][0] == 3)
	{
		k3 = 3;
	}
	if(a[2][0] == 4)
	{
		for(int i = 1; i <= 4; i++)
		{
			if(a[2][i] == 4)
			{
				k3 = i;
			}
		}
	}
	printf("%d %d\n", k3,a[2][k3]);

	//4
	//
	if(a[3][0] == 1)
	{
		k4 = k1;
	}
	if(a[3][0] == 2)
	{
		k4 = 1;
	}
	if(a[3][0] == 3 || a[3][0] == 4)
	{
		k4 = k2;
	}
//--------------5
	if(a[4][0] == 1)
	{
		for(int i = 1; i <= 4; i++)
		{
			if(a[4][i] == a[0][k1])
			{
				k5 = i;
			}
		}
	}
	if(a[4][0] == 2)
	{
		for(int i = 1; i <= 4; i++)
		{
			if(a[4][i] == a[1][k2])
			{
				k5 = i;
			}
		}

	}
	if(a[4][0] == 3)
	{
		for(int i = 1; i <= 4; i++)
		{
			if(a[4][i] == a[3][k1])
			{
				k5 = i;
			}
		}

	}
	if(a[4][0] == 4)
	{
		for(int i = 1; i <= 4; i++)
		{
			if(a[4][i] == a[2][k1])
			{
				k5 = i;
			}
		}
	}
	printf("%d %d\n", k5, a[4][k5]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		memset(a, 0, sizeof(a));
		for(int i = 0; i < 5; i++)
			for(int j = 0; j < 5; i++)
				scanf("%d", &a[i][j]);
		solve();
	}

    return 0;
}
