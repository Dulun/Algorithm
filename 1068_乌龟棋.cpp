/*************************************************************************
	> File Name: 1068_乌龟棋.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月05日 星期六 15时23分32秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
//四维dp，dp[i][j][k][l]:表示使用i，j，k，l张标有1,2,3,4的卡片能得到的最高分数
//---------------------------想不到，，看了题解-----------------
//状态转移方程：
//dp[t][i][j][k] = max(dp[t-1][i][j][k], dp[t][i-1][j][k], dp[t][i][j-1][k], dp[t][i][j][k-1]) + a[1*t+2*i+3*j+4*k];
const int N = 50086;

int dp[41][41][41][41];
int mov[5] = {1, 1, 1, 1, 1};
int a[400];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int j = 1; j <= m; j++) {int x; scanf("%d", &x); mov[x]++;}
 //   for(int i = 1; i <= 4; i++) printf("mov[%d] = %d\n", i, mov[i]);
 
    for(int i = 1; i <= mov[1]; i++)
    for(int j = 1; j <= mov[2]; j++)
    for(int k = 1; k <= mov[3]; k++)
    for(int l = 1; l <= mov[4]; l++)
    {
      //  printf("hello world\n");
        dp[i][j][k][l] = a[i-1+2*j-2+3*k-3+4*l-4+1] + max(dp[i][j][k][l-1], max(dp[i][j][k-1][l], max(dp[i][j-1][k][l],dp[i-1][j][k][l])));  
       // printf("%d\n", dp[i][j][k][l]);
    }
    printf("%d\n", dp[mov[1]][mov[2]][mov[3]][mov[4]]);
    return 0;
}
