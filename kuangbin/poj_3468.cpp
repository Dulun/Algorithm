/*************************************************************************
	> File Name: poj_3468.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月22日 星期二 21时34分26秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 111111;

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

LL add[N<<2];
LL sum[N<<2];

void pushup(int rt)
{
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}

void pushdown(int rt, int m)
{
    if(add[rt])
    {
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        sum[rt<<1] += (m-(m>>1)*add[rt]);
        sum[rt<<1|1] += (m>>1) * add[rt];
        add[rt] = 0;
    }
}

void build(int l, int r, int rt)
{
    add[rt] = 0;
    if(l == r)
    {
        scanf("%lld", &sum[rt]);
        return;
    }
    int m = (l+r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(int L, int R, int c, int l, int r, int rt)
{
    if(L <= l && R >= r)
    {
        add[rt] += c;
        sum[rt] += (LL)c*(r-l+1);
        return;
    }
    pushdown(rt, r-l+1);
    int m = (r+l)>>1;
    if(L <= m) update(L, R, c, lson);
    if(R > m)  update(L, R, c, rson);
    pushup(rt);
}

LL query(int L, int R, int l, int r, int rt)
{
    if(L<=l && R>= r) return sum[rt];
    pushdown(rt, r-l+1);
    int m = (l+r) >>1;
    LL ret = 0;
    if(L <= m) ret += query(L, R, lson);
    if(R > m) ret += query(L, R, rson);
    return ret;
}

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    build(1, n, 1);
    while(m--)
    {
        char s[5];
        int a, b, c;
        scanf("%s", s);
        if(s[0] == 'Q') 
        {
            scanf("%d%d", &a, &b);
            printf("%lld\n", query(a, b, 1, n, 1));
        }
        else
        {
            scanf("%d%d%d", &a, &b, &c);
            update(a, b, c, 1, n, 1);
        }
    }
    return 0;
}
