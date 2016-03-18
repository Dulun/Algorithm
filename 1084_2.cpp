/*************************************************************************
	> File Name: 1084_2.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月03日 星期四 20时16分12秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 201;

int dp[N][N][N];
int a[N][N];

int max_4(int a, int b, int c, int d)
{
    if(a >= b && a >= c && a >= d) return a;
    if(b >= a && b >= c && b >= d) return b;
    if(c >= a && c >= b && c >= d) return c;
    if(d >= a && d >= c && d >= b) return d;
}

int main()
{
    int m, n;
    cin>>m>>n;

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) scanf("%d", &a[i][j]);

    int d;
    for(int x1 = 1; x1 <= n; x1++)
    for(int x2 = 1; x2 <= n; x2++)
    for(int k = max(x1, x2)+1; k <= min(x1, x2)+m; k++)
    {
        if(x1 != x2) d = a[x1][k-x1] + a[x2][k-x2];
        else d = a[x1][k-x1];
        dp[k][x1][x2] = max(dp[k-1][x1-1][x2], max(dp[k-1][x1][x2-1],max( dp[k-1][x1-1][x2-1], dp[k-1][x1][x2]))) + d;
    }

    printf("%d\n", dp[m+n][n][n]);

    return 0;
}
