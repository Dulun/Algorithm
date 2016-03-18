/*************************************************************************
	> File Name: 111.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月11日 星期五 18时01分58秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50086;
int dp[208][10];

int f(int m, int p)
{
    if(dp[m][p] > 0) return dp[m][p];
    if(m < p) return 0;
    if(p == 1) return dp[m][p] = 1;

    return dp[m][p] = f(m-1, p-1) + f(m-p, p);
}

int main()
{
    int n, k;
    cin>>n>>k;

//    for(int i = 1; i <= n; i++) 
//    {
//        dp[i][1] = 1;
//        dp[i][i] = 1;
 //   }
    dp[0][0] = 1;

    f(n, k);
    cout<<dp[n][k]<<endl;

    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k ; j++ )
        {
            if(i >= j)
            dp[i][j] = dp[i-1][j-1] + dp[i-j][j];
        }
    }
   // cout<<dp[n][k];
}
