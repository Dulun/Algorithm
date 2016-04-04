/*************************************************************************
	> File Name: poj_1679.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年04月03日 星期日 17时38分34秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std; 
const int N = 50086;

bool first = 0;
int n, m;
int p[N];
struct Edge
{
    int s, e, w;
    bool same, use, del;
};
Edge e[N];

bool cmp(Edge a, Edge b) { return a.w < b.w; }
int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

void init()
{
    for(int i = 0; i < N; i++) p[i] = i;
}

int kruscal()
{
    int cnt = 0, ans = 0;
    init();
    for(int i = 0; i < m; i++)
    {
        if(e[i].del == true) continue;
        int x = find(e[i].s);
        int y = find(e[i].e);
        if( x!=y )
        {
            p[x] = y;
            ans+=e[i].w;
            if(first) e[i].use = true;
            cnt++;   
        }
        if(cnt == n-1) return ans;
    }
    return ans;
}


void findSameWeight()
{
    for(int i = 0; i < m; i++)
    for(int j = 0; j < m; j++)
    {
        if(i==j) continue;
        if(e[i].w == e[j].w) e[i].same = true;
    }
}

void sovle()
{
    sort(e, e+m, cmp);
    first = true;
    int ans_MST = kruscal();
    first = false;
    for(int i = 0; i < m; i++)
    {
        if(e[i].use && e[i].same)
        {
            e[i].del = true;
            int ans = kruscal();
            e[i].del = false;
            if(ans == ans_MST) 
            {
                printf("Not Unique!\n");
                return ;
            }
        }   
    }
    printf("%d\n", ans_MST);
    return;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; i++)
        {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            e[i].s = a, e[i].e = b, e[i].w = w;
            e[i].same = false;
            e[i].use = false;
            e[i].del = false;
        }
        findSameWeight();
        sovle();
    }
    return 0;
}
