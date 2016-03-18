/*************************************************************************
	> File Name: 1214.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月01日 星期二 13时23分41秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

struct node
{
    int a, b;
}l[10000];

bool cmp(node x, node y){ return x.b < y.b; }

int main()
{
    int n;
    cin>>n;
    int count = 0;
    int x, y;

    for(int i = 0; i < n; i++)
    {
        cin>>x>>y;
        if(x < y) l[i].a = x, l[i].b = y;
        else      l[i].a = y, l[i].b = x;
    }
    
    sort(l, l + n, cmp);
    int res = 0, max = -10000;

    for(int i = 0; i < n; i++)
    {
        if(l[i].a >= max)
        {
            res++;
            max = l[i].b;
        }
    }
    cout<<res;
    return 0;
}
