/*************************************************************************
	> File Name: 1014.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月10日 星期四 18时30分03秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50086;
int a[32];
int dp[N];

int main()
{
    int v, n; 
    cin>>v>>n;
    for(int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        for(int j = v; j >= t; j--)
        {
            if(dp[j-t] + t > dp[j]) dp[j] = dp[j-t] + t;
        }
    }
    printf("%d\n", v-dp[v]);

//    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
//
//
//    for(int i = v; i >= 0; i--)
//    for(int j = 1; j <= n; j++)
//    {
//        if(i < a[j]) continue;
//        dp[i] = max(dp[i-a[j]]+a[j], dp[i]);
//    }
//    printf("%d\n", v-dp[v]);
//
    return 0;
}
