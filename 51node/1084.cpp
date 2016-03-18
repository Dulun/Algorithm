/*************************************************************************
	> File Name: 1084.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月03日 星期四 19时08分48秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 506;
int a[N][N] = {};
int dp[N][N][N] = {};


int max_4(int a, int b, int c, int d)
{
    if(a >= b && a >= c && a >= d) return a;
    if(b >= a && b >= c && b >= d) return b;
    if(c >= a && c >= b && c >= d) return c;
    if(d >= a && d >= c && d >= b) return d;
}

int main()
{
   // cout<<max_4(8, 8, 2, 4);
    int hang, lie;
    cin>>lie>>hang;

    for(int i = 1; i <= hang; i++)
    for(int j = 1; j <= lie;  j++) scanf("%d", &a[i][j]);

    int st = 1;
    for(st = 1; st <= (hang+lie-1); st++)
    {
        for(int hang1 = 1; hang1 < hang; hang1++)
        {
            for(int hang2 = 1; hang2 < hang; hang2++)
            {
                if(hang1 != hang2)
                {
                    dp[st][hang1][hang2] = max_4(dp[st-1][hang1][hang2], dp[st-1][hang1-1][hang2], dp[st-1][hang1][hang2-1], dp[st-1][hang1-1][hang2]);
                    dp[st][hang1][hang2] += a[hang1][st-hang1+1] + a[hang2][st-hang2+1];
                }
                if(hang1 == hang2)
                {
                    dp[st][hang1][hang2] = max_4(dp[st-1][hang1][hang2], dp[st-1][hang1-1][hang2], dp[st-1][hang1][hang2-1], dp[st-1][hang1-1][hang2]);
                    dp[st][hang1][hang2] += a[hang1][st-hang1+1];
                }
                    printf("dp[%d][%d][%d] = %d \n",st, hang1, hang2, dp[st][hang1][hang2]);
            }
        }
    }
    printf("%d", dp[st-1][hang][lie]);
    return 0;
}
