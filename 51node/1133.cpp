/*************************************************************************
        > File Name: 1133.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月27日 星期三 13时42分14秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 10086;
struct Node
{
    int a, b;
};

Node line[N];
bool cmp(Node a, Node b) {return a.b < b.b;}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d", &line[i].a, &line[i].b);
    }
    sort(line, line+n, cmp);
    int ans = 1;
    int l = line[0].b;
    for(int i = 1; i < n; i++)
    {
        if(l <= line[i].a)
        {
            l = line[i].b;
            ans++;
        }   
    }
    cout<<ans<<endl;

 
    return 0;
}
