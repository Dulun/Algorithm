/*************************************************************************
	> File Name: hdu_1260.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月05日 星期六 11时53分23秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 2086;

int a[N];
int b[N];
int dp[N];

int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int k;
        scanf("%d", &k);
        memset(dp, 0, sizeof(dp));
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        
        for(int i = 0; i < k; i++)
        {
            scanf("%d", &a[i+1]);
        }
        
        for(int i = 0; i < k - 1; i++)
        {
            scanf("%d", &b[i+2]);
        }
     
/*        
        for(int i = 2; i <= k; i++)
        {
            dp[i][0] = min(dp[i-1][0], dp[i-2][1] ) + a[i];
            dp[i][1] = dp[i-1][0] - a[i-1] + b[i-1];
        }
        int t = dp[k][0]>dp[k][1] ? dp[k][1] : dp[k][0];
*/        
        dp[1] = a[1];
        for(int i = 2; i <= k; i++)
        {
            dp[i] = min(dp[i-1]+a[i] , dp[i-2]+b[i]);
        }
        int t = dp[k];
        int hh, mm, ss;
        hh = t/3600;
        mm = t%3600/60;
        ss = t%60;
        printf("%02d:%02d:%02d%s\n", (8+hh)%24, mm, ss, (hh+8)%24>12?" pm":" am");        
    }
 
    return 0;
}
