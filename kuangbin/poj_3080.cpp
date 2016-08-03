/*************************************************************************
        > File Name: poj_3080.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年05月18日 星期三 00时22分22秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 586;
char now[N][N];
char s[N];

void find(int k)
{
    int dp[N][N] = {0};
    int la = strlen(now[k]+1);
    int lb = strlen(s+1);
    int cnt = 0;
    int where = 0;
    for(int i = 1; i < la+1; i++)
    {
        for(int j = 1; j < lb+1; j++)
        {
            if(now[k][i] == s[j])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            if(dp[i][j] > cnt)
            {
                cnt = dp[i][j];
                where = i;
            }
        }
    }
    memset(s, 0, sizeof(s));
    int p = 1 + where - cnt;
    for(int i = 1; i <= cnt; i++)
    {
        s[i] = now[k][p++];
    }
    s[cnt+1] = 0;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n; 
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%s", now[i]+1);
        }
        int len = strlen(now[0]+1);
        for(int i = 1; i < len+1; i++)
        {
            s[i] = now[0][i];
        }
        for(int i = 1; i < n; i++)
        {
            find(i);
        }
        if(strlen(s+1) < 3)
        {
            printf("no significant commonalities\n");
        }
        else{
            printf("%s\n", s+1);
        }
    }
 
    return 0;
}
