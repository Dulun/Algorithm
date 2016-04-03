/*************************************************************************
	> File Name: poj_3206.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年04月03日 星期日 14时44分02秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>

#define LL long long
using namespace std;
const int inf = 1<<30; 
const int N = 256;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char G[N][N];
int node[N][N];
bool v[N][N];
int dis[N][N];
int num[N][N];
int n, m, cnt;
struct P
{
    int x, y;
};

void bfs(int i, int j)
 {
    queue<P> Q;
    memset(v, 0, sizeof(v));
    Q.push((P){i, j});
    dis[i][j] = 0;
    v[i][j] = 1;

    while(!Q.empty())
    {
        P e = Q.front(); Q.pop();
        int x = e.x, y = e.y;
        if(num[x][y] != -1) node[num[i][j]][num[x][y]] = dis[x][y];
        for(int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx < 0 || yy < 0 ) continue;
            if(v[xx][yy] || G[xx][yy] == '#') continue;
            v[xx][yy] = 1;
            dis[xx][yy] = dis[x][y] + 1;
            Q.push((P){xx, yy});
        }
    }
}

int prim(int s)
{
    int d[N], v[N];
    int ans = 0;
    memset(v, 0, sizeof(v));
    for(int i = 0; i < cnt; i++) d[i] = node[s][i];
    v[s] = 1;
    d[s] = 0;

    for(int i = 0; i < cnt-1; i++)
    {
        int k, min = inf;
        for(int j = 0; j < cnt; j++)
        if(!v[j] && d[j] < min) min = d[k=j];
        v[k] = 1;
        ans+=min;
        for(int j = 0; j < cnt; j++) 
        if(!v[j] && d[j] > node[k][j]) d[j] = node[k][j];
    }
    return ans;
}

int main()
{
    int T, n, m, ns;
    char tmp[N];
    cin>>T;

    while(T--)
    {
        scanf("%d%d", &m, &n);
        gets(tmp);
        for(int i = 0; i < n; i++) gets(G[i]);
        cnt = 0;
        memset(num, -1, sizeof(num));

        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(G[i][j] == 'S' || G[i][j] == 'A') num[i][j] = cnt++;
            if(G[i][j] == 'S') ns = cnt -1;
        }
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        if(G[i][j] == 'A' || G[i][j] == 'S') bfs(i, j);
        printf("%d\n", prim(ns));
    }
    return 0;
}
