/*************************************************************************
        > File Name: b.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月24日 星期日 13时02分54秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 186;
char g[N][N] = {0};
int dx[] = {2, 1, -1, -2};
int dy[] = {1, 2, -2, -1};

int n, m;
int a, b, c, d;
bool v[N][N];

void dfs(int x, int y, int cur)
{
	if(x == c && y == d)
	{
		ans = min(ans, cur)
	}

	for(int i = 0; i < 4; i++)
	{
		int tui;
		int xx = x + dx[i];
		int yy = x + dy[i];
		int k1 = abs(dx[i]);
		int k2 = abs(dy[i]);
		if(k1 > k2)

	}
}

int main()
{
	while(~scanf("%d%d", &n, &m))
	{
		memset(v, 0, sizeof(v));
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
			{
				scanf("%c",&a[i][j]);
				if(a[i][j] == 's')
				{
					a = i;
					b = j;
				}
				if(a[i][j] == 'e')
				{
					c = i;
					d = j;
				}
			}
		dfs(a, b);


	}

    return 0;
}
