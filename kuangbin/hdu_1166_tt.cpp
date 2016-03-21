/*************************************************************************
	> File Name: hdu_1166_tt.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月21日 星期一 16时13分18秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
const int N = 50086;

struct Node
{
    int l, r, sum;
};

Node t[3*N];
int a[N];

void build(int l, int r, int i)
{
    t[d].l = l;
    t[d].r = r;
    if(l == r) 
    {
        t[d].sum = a[l];
        return ;
    }

    int m = (l+r) / 2;
    build(l, m, i<<1);
    build(m+1, r, (i<<1)+1);
    t[d].sum = t[d<<1].sum + t[d(<<1)+1].sum;
}

void add(int id, int num, int d)
{
    t[d].sum += num;
    if(t[d].l == t[d].r) return;

    if(t[d<<1].l >= l) add(id, num, d<<1);
    else add(id, num. (d<<1)+1);
}

int query(int l, int r, int d)
{
    if(t[d].l == l && r == t[d].r) return t[d].sum;

    int m = (t[d].l + t[d].r) / 2;
    if(r <= m) return query(l, r, d<<1);
    if(l > m)  return query(l, r, (d<<1) + 1);
    return query(l, m, d<<1)+query(m+1, r, (d<<1)+1);   
}

int main()
{
    int T;
    int cnt = 0;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        for(int i = 1; i <=n; i++)
        {
            scanf("%d", &a[i]);
        }
        build(1, n, 1);
        printf("Case %d:\n", ++cnt);
        
        char order[10];
        while(scanf("%s", order) && order[0] != 'E')
        {
            int a, b;
            scanf("%d%d", &a, &b);
            if(order[0] == 'A')
            {
                add(a, b, 1);
            }
            if(order[0] == 'S')
            {
                add(a, -b, 1);
            }
            if(order[0] == 'Q')
            {
                printf("%d\n", query(a, b, 1));
            }
            memset(order, 0, sizeof(order));
        }
    }
 
    return 0;
}
