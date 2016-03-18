/*************************************************************************
	> File Name: 1166——矩阵取数游戏.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月08日 星期二 18时20分52秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define LL long long
using namespace std;
 
const int N = 108;
LL dp[N][N];
int a[N][N];
int p[N][2];


int main()
{
    int  m, n;
    LL ans = 0;
    scanf("%d%d", &n, &m);
 
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++) scanf("%d", &a[i][j]);

    for(int hang = 1; hang <= n; hang++)
    {
        for(int i = 1; i <= m; i++) dp[i][i] = a[hang][i];
        for(int i = 1; i <= m-1; i++)
        {
            for(int start = 1; start <= m-i; start++)
            {
                int end = start+i;
                dp[start][end] = max(dp[start+1][end]*2 + a[hang][start], dp[start][end-1]*2 + a[hang][end]);
            }
        }
        ans += 2*dp[1][m];
    }
    cout<<ans<<endl;

    return 0;
}
