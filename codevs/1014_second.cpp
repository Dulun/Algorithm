/*************************************************************************
	> File Name: 1014_second.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月18日 星期五 12时04分21秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50086;
int dp[N];

int main()
{
    int n, v;
    scanf("%d%d", &v, &n);
    for(int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);
        for(int j = v; j>=t; j--)
        {
            dp[j] = max(dp[j], dp[j-t]+t);
        }
    }
    cout<<v-dp[v];
  
    return 0;
}
