/*************************************************************************
        > File Name: f.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月24日 星期日 16时02分55秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 26;
int a[N][N];
bool v[N];
LL ans = 0;
int n = 0;

void dfs(int cur, int k)
{
	if(k == n)
	{
		ans++;
		return;
	}
	for(int i = 1; i <= n; i++)
	{
		if(i == cur) continue;
		if(!v[i] && a[cur][i]==1)
		{
			v[i] = 1;
			dfs(i, k+1);
			v[i] = 0;
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
		memset(v, 0, sizeof(v));
		ans = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
			{
				scanf("%d", &a[i][j]);
			}
/*		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				for(int k=1; k<=n; k++)
					if(a[i][k]==1 && a[k][j]==1)
						a[i][j] = 1;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
				printf("%d ", a[i][j]);
			cout<<endl;
		}
*/
		LL k = 0;
		v[1] = 1;
		dfs(1, 1);
		printf("%lld\n", ans);
	}
    return 0;
}
