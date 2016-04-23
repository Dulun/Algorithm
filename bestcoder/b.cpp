/*************************************************************************
        > File Name: b.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月22日 星期五 19时45分26秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 1086;
int a[N][N];
struct Node
{
	int op;
	int x;
	int y;
};
Node k[100009];

int n, m, q;
void swap_hang(int x, int y)
{
	x--;
	y--;

	int t[N] = {0};
	for(int i = 0; i < m; i++)
	{
		t[i] = a[x][i];
	}
	for(int i = 0; i < m; i++)
	{
		a[x][i] = a[y][i];
	}
	for(int i = 0; i < m; i++)
	{
		a[y][i] = t[i];
	}
}
void swap_lie(int x, int y)
{
	x--;
	y--;

	int t[N] = {0};
	for(int i = 0; i < n; i++)
	{
		t[i] = a[i][x];
	}
	for(int i = 0; i < n; i++)
	{
		a[i][x] = a[i][y];
	}
	for(int i = 0; i < n; i++)
	{
		a[i][y] = t[i];
	}
}

void add_hang(int x, int y)
{
	x--;
	for(int i = 0; i < m; i++)
	{
		a[x][i] += y;
	}
}
void add_lie(int x, int y)
{
	x--;
	for(int i = 0; i < n; i++)
	{
		a[i][x] += y;
	}
}


int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &n, &m, &q);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				scanf("%d", &a[i][j]);
		for(int i = 0; i < q; i++)
		{
			int op, x, y;
			scanf("%d%d%d", &op, &x, &y);
			if(op == 1)
			{
				swap_hang(x, y);
			}
			if(op == 2)
			{
				swap_lie(x, y);
			}
			if(op == 3)
			{
				add_hang(x, y);
			}
			if(op == 4)
			{
				add_lie(x, y);
			}
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m-1; j++)
			{
				printf("%d ", a[i][j]);
			}
			printf("%d\n", a[i][m-1]);
		}
	}
    return 0;
}
