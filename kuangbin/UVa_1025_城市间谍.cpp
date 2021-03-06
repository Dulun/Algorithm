/*************************************************************************
	> File Name: UVa_1025_城市间谍.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月10日 星期四 15时39分49秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int INF = 1<<30;

int main()
{
    int kase = 0;
    while(1)
    {
        int n, T, M1, M2;
        bool has[255][255][2] = {0};
        int t[255] = {0};
        int d[255] = {0};
        int e[255] = {0};
        int ct[255] = {0};
        int dp[255][255] = {0};
        
        scanf("%d", &n);
        if(n == 0) break;
        scanf("%d", &T);
        
        for(int i = 1; i <= n-1; i++) {scanf("%d", &t[i]); ct[i+1] = ct[i]+t[i];}//printf("ct[%d] = %d", i, ct[i+1]);}
        ct[1] = 0;
        t[n] = 0;
        
        scanf("%d", &M1);
        for(int i = 1; i <= M1; i++) scanf("%d", &d[i]);
        
        scanf("%d", &M2);
        for(int i = 1; i <= M2; i++) scanf("%d", &e[i]);
        
        for(int i = 1; i <= M1; i++)
        for(int j = 1; j <= n;   j++) has[d[i]+ct[j]][j][0] = 1;
        for(int i = 1; i <= M2; i++)
        for(int j = 1; j <= n;   j++) has[e[i]+ct[n]-ct[n-j+1]][n-j+1][1] = 1;
        
      
        for(int i = 1; i < n; i++) dp[T][i] = INF;
        dp[T][n] = 0;
        
        for(int i = T-1; i >= 0; i--)
        for(int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i+1][j] + 1;
            if( j < n && has[i][j][0] && i+t[j] <= T) dp[i][j] = min(dp[i][j], dp[i+t[j]][j+1]);
            if( j > 1 && has[i][j][1] && i+t[j-1] <= T) dp[i][j] = min(dp[i][j], dp[i+t[j-1]][j-1]);
        }
        
        printf("Case Number %d: ", ++kase);
        if(dp[0][1] >= INF) printf("impossible\n");
        else printf("%d\n", dp[0][1]);
    }
    return 0;
}

