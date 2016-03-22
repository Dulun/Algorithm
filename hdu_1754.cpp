/*************************************************************************
	> File Name: hdu_1754.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月21日 星期一 22时33分58秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 200086;
int a[N];
struct Node
{
    int l, r, mxc;
};
Node t[2000000];

void build(int l, int r, int d)
{
    t[d].l = l;
    t[d].r = r;
    if(l == r)
    {
        t[d].mxc = a[l];
        return;
    }
    int m = (l + r) / 2;
    
    build(l, m, d<<1);
    build(m+1, r, (d<<1)+1);

    t[d].mxc = max(t[d<<1].mxc, t[(d<<1)+1].mxc);
}

int change(int id, int num, int d)
{
    if(t[d].l == id && t[d].r == id)
    {
        return t[d].mxc = num;
    }

    int m = (t[d].l + t[d].r) / 2;
    if( id <= m ) return t[d].mxc = max(t[d<<1|1].mxc, change(id, num, d<<1));
    else return t[d].mxc = max(t[d<<1].mxc, change(id, num, d<<1|1));
}
 
int query(int l, int r, int d)
{
    if(t[d].l == l && t[d].r == r)
    {
        return t[d].mxc;
    }
    int m = (t[d].l + t[d].r) / 2;
    if(r <= m) return query(l, r, d<<1);
    if(l > m) return query(l, r, (d<<1)+1);
    return max(query(l, m, d<<1), query(m+1, r, (d<<1)+1));
}

 
int main()
{

    int n, k;
    while(~scanf("%d%d", &n, &k))
    {
        memset(a, 0, sizeof(a));
        memset(t, 0, sizeof(t));
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        build(1, n, 1);
        for(int i = 0; i < k; i++)
        {
            char o;
            int x, y;
            scanf("%*c%c%d %d", &o, &x, &y);//?????????
            if(o == 'U')
            {
                a[x] = y;
                change(x, y, 1);
            }
            if(o == 'Q')
            {
                printf("%d\n", query(x,y, 1));
            }
        }
    }

 
    return 0;
}
