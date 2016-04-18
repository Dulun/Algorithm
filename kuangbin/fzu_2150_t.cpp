/*************************************************************************
        > File Name: fzu_2150_t.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月13日 星期三 20时44分39秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<vector>
#include<algorithm>
#define LL long long
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 50086;
struct Node
{
	int x, y, cnt;
};
int m, n;
vector<Node> v;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char g[15][15];
bool vis[15][15];

int bfs(Node a, Node b)
{
	memset(vis, 0, sizeof(vis));
	queue<Node> q;
	vis[a.x][a.y] = vis[b.x][b.y] = true;
	int ans = inf;
	q.push(a);
	q.push(b);

	while(!q.empty())
	{
		a = q.front();
		q.pop();
		ans = a.cnt;
		for(int i = 0; i < 4; i++)
		{
			b.x = a.x + dx[i];
			b.y = a.y + dy[i];
			b.cnt = a.cnt+1;
			if(!vis[b.x][b.y] && g[b.x][b.y] == '#' && b.x>0 && b.y>0 && b.x<=n && b.y<=m )
			{
				vis[b.x][b.y] = true;
				q.push(b);
			}
		}
	}
	return ans;

}

int main()
{
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		v.clear();
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
		{
			getchar();
			for(int j = 1; j <= m; j++)
			{
				scanf("%c", &g[i][j]);
				if(g[i][j]  == '#')
				{
					v.push_back((Node){i, j, 0});
				}
			}
		}
		int ans = inf;
		for(int i = 0; i < v.size(); i++)
		{
			for(int j = 0; j < v.size(); j++)
			{
				int tmp = bfs(v[i], v[j]);
				bool ok = true;

				for(int k = 1; k <= n; k++)
				{
					for(int f = 1; f <= m; f++)
					{
						if(!vis[k][f] && g[k][f] == '#')
						{
							ok = false;
							break;
						}
					}
					if(ok == false) break;
				}
				if(ok) ans = min(ans, tmp);
			}
		}
		printf("Case %d: ", cas);
		if(ans == inf) printf("-1\n");
		else		   printf("%d\n", ans);
	}
    return 0;
}
