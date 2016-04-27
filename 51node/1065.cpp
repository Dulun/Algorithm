/*************************************************************************
        > File Name: 1065.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月27日 星期三 14时40分34秒
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
    LL s;
    int pos;
};
Node a[N];

bool cmp(Node p, Node q) {
    return p.s < q.s;
}

int main()
{
    int n;
    LL sum, t, ans;
    a[0].pos = 0;
    a[0].s = 0;
    sum = 0;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &t);
        sum += t;
        a[i].pos = i;
        a[i].s = sum;
    }
    sort(a, a+n+1, cmp);

    ans = 0x3f3f3f3f;
    for(int i = 1; i <= n; i++)
    {
        if(a[i].pos > a[i-1].pos && a[i].s > a[i-1].s)
        {
            ans = min(ans, a[i].s-a[i-1].s);
        }
    }
    printf("%lld\n", ans);
 
    return 0;
}
