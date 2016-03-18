/*************************************************************************
	> File Name: 1220_数字三角形.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月09日 星期三 22时33分00秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 109;
int dp[N][N];
int a[N][N];

int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= i; j++)
    {
        scanf("%d", &a[i][j]);
    }

    for(int i = 1; i <= n; i++) dp[n][i] = a[n][i];

    for(int i = n-1; i >= 1; i--)
    for(int j = 1; j <= n; j++)
    {
        dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]);
    }
    cout<<dp[1][1];
    return 0;
}
