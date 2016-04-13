t/*************************************************************************
	> File Name: 1.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月04日 星期五 21时41分59秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 100086;
int num[15][N];
int dp[15][N];



int main()
{
    int n;

    while(~scanf("%d", &n) && n)
    {
        memset(dp, 0, sizeof(dp));
        memset(num, 0, sizeof(num));
        int ma = 0;
        int T = 0;
        for(int i = 0; i < n; i++)
        {
            int t, x;
            scanf("%d%d", &x, &t);
            num[x+1][t]++;
            if(t > T) T = t;
        }

        for(int t = 1; t <= T; t++)
        {
            int l = t<6 ? 6-t : 1;
            int r = t<6 ? 6+t : 11;
            for(int i = l; i <= r; i++)
            {
                dp[i][t] = num[i][t] + max(dp[i][t-1], max(dp[i+1][t-1], dp[i-1][t-1]));
            }
            for(int i = 1; i <= 11; i++)
                if(dp[i][T] > ma)
                    ma = dp[i][T];
        }
        cout<<ma<<endl;
    }

    return 0;
}
