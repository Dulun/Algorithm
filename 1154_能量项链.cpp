/*************************************************************************
	> File Name: 1154_能量项链.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月08日 星期二 13时21分00秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 208;

int dp[N][N];

struct Node
{
    int l,r;
};
Node a[N];


int main()
{
    int n, t;
    cin>>n;

    scanf("%d", &t);
    for(int i = 1; i < n; i++)
    {
        a[i].l = t;
        scanf("%d", &t);
        a[i].r = t;
    }
    a[n].l = t;
    a[n].r = a[1].l;
  //  printf("123412431243\n");

    for(int i = n+1; i <= 2*n; i++)
    {
        a[i] = a[i-n];
    }

 //   for(int i = 1; i <= 2*n; i++)
 //   {
      //  printf("(%d, %d) ", a[i].l, a[i].r);
 //   }
    for(int len = 2; len <= n; len++)
    {
        for(int start = 1; start <= 2*n - len + 1; start++)
        {
            int end = start + len-1;
            for(int k = start; k < end; k++)
            {
                dp[start][end] = max(dp[start][end], dp[start][k]+dp[k+1][end] + a[start].l*a[k].r*a[end].r);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i][i+n-1]);
    }
    printf("%d\n", ans);
 
    return 0;
}
