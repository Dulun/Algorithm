/*************************************************************************
	> File Name: 1201_整数划分.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月11日 星期五 20时11分18秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 5086;
const int INF = 1000000007;
int dp[N][N];

int main()
{
    int n;
    cin>>n;

    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    {
        if(i >= j)
        dp[i][j] = (dp[i-1][j-1] + dp[i-j][j]) % INF;
    }
 
    LL ans = 0;
    for(int i = 1; i <= n; i++)
        ans += dp[n][i] % INF;

    cout<<ans;
    return 0;
}
