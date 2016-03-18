/*************************************************************************
	> File Name: 1083.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月03日 星期四 17时15分33秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 508;

int a[N][N] = {0};
int dp[N][N] = {0};

int main()
{
    int n;
    cin>>n;
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) scanf("%d", &a[i][i]);

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    {
        dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + a[i][j];
        cout<<dp[i][j]<<endl;
    }
    cout<<dp[n][n];
 
    return 0;
}
