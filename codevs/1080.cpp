/*************************************************************************
        > File Name: 1080.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年05月11日 星期三 19时04分33秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50086;
int a[N];
int sum[N] = {0};
 
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        sum[i] = sum[i-1] + a[i];
    }
    int m;
    scanf("%d", &m)
    for(int i = 0; i < m; i++)
    {
    }
 
    return 0;
}
