/*************************************************************************
	> File Name: 1017_乘积最大.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月11日 星期五 17时03分54秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50;
int map[N][N];
int dp[N][10];

 
int main()
{
    int n, k;
    cin>>n>>k;

    char a[N];
    cin>>a;

    for(int i = 0; i < n; i++)
    {
        int m = 0;
        for(int j = i; j < n; j++)
        {
            m = m * 10 + a[j] - '0';
            map[i][j] = m;
        }
    }

    for(int i = 0; i < n; i++) dp[i][0] = map[0][i];

    for(int i = 0; i < n; i++)
    for(int j = 1; j <= k; j++)
    for(int t = 0; t < i; t++)
    {
        dp[i][j] = max(dp[t][j-1]*map[t+1][i], dp[i][j]);
    }
 
    cout<<dp[n-1][k]<<endl;
    return 0;
}
