/*************************************************************************
	> File Name: 快速幂.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月16日 星期三 18时58分07秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
#define LL long long

const LL INF = 1000000009;

LL n;

struct Node
{
    LL c[2][2];
}t;

Node mult(Node a, Node b)
{
    Node c = {0};
    for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
    for(int k = 0; k < 2; k++)
    {
        c.c[i][j] += (a.c[i][k] * b.c[k][j]) % INF;
        c.c[i][j] %= INF;
    }
    return c;
}

Node pow(LL n)
{
    Node pt = t;
    if(n < 0) return pt;
    while(n)
    {
        if( n & 1 )
        {
            pt = mult(pt, t);
            n--;
        }
        t = mult(t, t);
        n >>= 1;
    }
    return pt;
}

int main()
{
    while(cin>>n)
    {
        t.c[0][0] = 1;
        t.c[0][1] = 1;
        t.c[1][0] = 1;
        t.c[1][1] = 0;
        Node ans = pow(n-2);
        printf("%lld\n", ans.c[0][0] * 1);
    }
    return 0;
}
