/*************************************************************************
        > File Name: 1148_传球游戏.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月16日 星期六 11时43分50秒
 ************************************************************************/

#include<stdio.h>
using namespace std;

const int N = 35;
int n, m;
int a[N][N];
bool v[N][N];

int dfs(int cur, int d)
{
	if(d < 0) return 0;
	if(v[cur][d]) return a[cur][d];
	v[cur][d] = true;
	return a[cur][d] = dfs( (cur-1+n) % n, d-1) + dfs((cur+1) % n,  d-1);
}
int main()
{
	scanf("%d%d", &n, &m);

	a[0][0] = 1;
	v[0][0] = 1;
	a[0][m] = dfs(n-1, m-1) + dfs(1, m-1);
	printf("%d\n", a[0][m]);
	return 0;
}
