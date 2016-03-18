/*************************************************************************
	> File Name: 1048.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月06日 星期日 16时37分29秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 1086;
int dp[N][N];
int a[N];
int sum[N];

int main()
{
    int n; 
    cin>>n;
    for(int i = 1; i <= n; i++) 
    {
        cin>>a[i];
        sum[i] = sum[i-1]+a[i];
    }

    for(int l = 2; l <= n; l++)
    {
        for(int i = 1; i <= n - l + 1; i++)
        {
            int j = i+l - 1;
            int min = 99999999;
            for(int k = i; k < j; k++)
            {
                if(dp[i][k]+dp[k+1][j] + sum[j] - sum[i-1] < min)
                    min = dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1];
            }
            dp[i][j] = min;
        }
    }
    cout<<dp[1][n];
    return 0;
}

