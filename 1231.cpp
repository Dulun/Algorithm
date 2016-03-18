/*************************************************************************
	> File Name: 1231.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年02月29日 星期一 14时08分49秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct computer
{
    int a,b,c;
};
computer com[100086];
int p[100086];
int m, n;

int find(int a){return p[a] == a ? a : p[a] = find(p[a]);}
int cmp(computer a, computer b){return a.c < b.c;}

int kruscal()
{
    long long sum = 0;
    int ans = 0;
    for(int i = 0; i < m && ans < n; i++)
    {
        int x = find(com[i].a);
        int y = find(com[i].b);
        if( x != y )
        {
            sum += com[i].c;
            p[x] = y;
            ans++;
        }
    }
    cout<<sum<<endl;
    return 0;
}

int main()
{
    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        p[i] = i;
    }

    for(int i = 0; i < m ; i++)
    {
        cin>>com[i].a;
        cin>>com[i].b;
        cin>>com[i].c;
    }
    sort(com, com + m, cmp);
    kruscal();
    return 0;
}
