/*************************************************************************
	> File Name: 1086.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月03日 星期四 12时03分55秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

const int N = 50086;

int dp[N]= {};
int w[N];
int p[N];
int c[N];

int main()
{
    int n, W;
    cin>>n>>W;

    for(int i = 1; i <= n; i++)
    {
        cin>>w[i]>>p[i]>>c[i];
    }

    for(int i = 1; i <= n; i++)
    {
        for( int k = 1; k <= c[i]; c[i] -= k, k <<= 1)
        {
            for(int j = W ; j >= w[i]*k; j--)
            {
                dp[j] = max(dp[j-w[i] * k] + p[i]*k, dp[j]);
                //printf("dp[%d] = %d\n", j, dp[j]);
            }
        }
        for(int j = W; j >= w[i] * c[i]; j--)
        {
            dp[j] = max(dp[j-w[i]*c[i]] + p[i] * c[i], dp[j]);
             //   printf("dp[%d] = %d\n", j, dp[j]);
        }
    }
    cout<<dp[W];
}
