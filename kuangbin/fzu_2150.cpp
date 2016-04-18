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
	int x, y, n;
};
int m, n, c;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char g[15][15];
bool vv[15][15];
void init()
{
	memset(g, 0, sizeof(g));
}

int bfs(int x1, int y1, int x2, int y2)
{
	int ans = inf;
	queue<Node> q;
	memset(vv, 0, sizeof(vv));
	Node s, t;
	vv[x1][y1] = 1;
	vv[x2][y2] = 1;
	s = (Node){x1, y1, 0};
	t = (Node){x2, y2, 0};
	q.push(s);
	q.push(t);

	while(!q.empty())
	{
		t = q.front();
		q.pop();
		vv[t.x][t.y] = 1;
		ans = t.n;

		for(int i = 0; i < 4; i++)
		{
			s.x = t.x + dx[i];
			s.y = t.y + dy[i];
			s.n = t.n + 1;
			if(!vv[s.x][s.y] && g[s.x][s.y] == '#' && s.x>0 && s.y>0 && s.x<=n && s.y<=m)
			{
				vv[s.x][s.y] = 1;
				q.push(s);
			}
		}
	}
	return ans;
}

bool check()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(!vv[i][j] && g[i][j] == '#')
				return false;
		}
	}
	return true;
}

void sovle()
{
	int ans = inf;
	bool flag = 0;
	bool v[15][15][15][15] = {0};

	for(int x1 = 1; x1 <= n; x1++)
	{
		for(int y1 = 1; y1 <= m; y1++)
		{
			if(g[x1][y1] == '.') continue;

			for(int x2 = 1; x2 <= n; x2++)
			{
				//flag = 0;
				for(int y2 = 1; y2 <= m; y2++)
				{
					if(g[x2][y2] == '.') continue;
					//if(v[x1][y1][x2][y2] || v[x2][y2][x1][y1] )
				//		continue;
					else{
						//v[x1][y1][x2][y2] = true;
						//v[x2][y2][x1][y1] = true;
						if(check())
							ans = min(ans, bfs(x1, y1, x2, y2));
					}
				}
				//if(flag == 1) break;
			}
		}
	}
	printf("Case %d:", c);
	if(ans == inf) printf("-1\n");
	else printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	for(c = 1; c <= T; c++)
	{
		init();
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
			scanf("%s", g[i]);
		//for(int i = 1; i<=n; i++)
		//	cout<<g[i]<<endl;
		sovle();
	}
	return 0;
}
