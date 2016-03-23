/*************************************************************************
	> File Name: poj_3126.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月23日 星期三 14时18分04秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define LL long long
using namespace std;
 
const int N = 10000;

int n;
bool prim[10009];
int ans = 0;
bool check(int k)
{
    if(k == 0 || k == 1) return 0;
    if(k == 3 || k == 2) return 1;
    for(int i = 2; i*i <= k; i++)
    {
        if(k % i == 0) return 0;
    }
    return 1;
}
 
void init()
{
    for(int i = 1000; i < N; i++)
    {
        if(check(i)) prim[i] = 1;
        else prim[i] = 0;
    }
}

int bfs(int first, int last)
{
    queue<int > q;
    bool v[N];
    int t[5];
    int dis[N];

    memset(dis, 0, sizeof(dis));
    memset(t, 0, sizeof(t));
    memset(v, 0, sizeof(v));

    v[first] = 1;
    q.push(first);

    while(!q.empty())
    {
        int x = q.front();
        if(x == last) return dis[x];
        q.pop();
        
        t[0] = x / 1000;
        t[1] = x % 1000 / 100;
        t[2] = x % 100 / 10;
        t[3] = x % 10;
        
        for(int i = 0; i <= 3; i++)
        {
            int k = t[i];
            for(int j = 0; j <=  9; j++)
            {
                if(j != t[i])
                {
                    t[i] = j;
                    int a = 1000*t[0]+100*t[1]+10*t[2]+t[3];
                    if(!v[a] && prim[a])
                    {
                        q.push(a);
                        dis[a] = dis[x]+1;
                        v[a] = 1;
                    }
                    if(a == last) return dis[a];
                }
            }
            t[i] = k;
        }
    }
    return -1;
}
 
int main()
{
    init();
    scanf("%d", &n);
    int a, b;
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        int ans = bfs(a, b);
        if(ans != -1) printf("%d\n", ans);
        else printf("Impossible\n");
    }
    return 0;
}
