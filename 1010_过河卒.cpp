/*************************************************************************
	> File Name: 1010_过河卒.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月09日 星期三 13时38分05秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 25;
int ans = 0;
int dp[N][N];
int end_x, ma_x;
int end_y, ma_y;



int main()
{
    scanf("%d%d", &end_x, &end_y);
    scanf("%d%d", &ma_x, &ma_y);
 
    for(int i = 0; i <= end_x; i++)
    for(int j = 0; j <= end_y; j++) dp[i][j] = 1;

    dp[ma_x][ma_y] = 0;
    dp[ma_x+2][ma_y+1] = 0;
    dp[ma_x+1][ma_y+2] = 0;
    if(ma_x>=1) dp[ma_x-1][ma_y+2] = 0;
    if(ma_x>=2) dp[ma_x-2][ma_y+1] = 0;
    if(ma_x>=2&&ma_y>=1) dp[ma_x-2][ma_y-1] = 0;
    if(ma_x>=1&&ma_y>=2) dp[ma_x-1][ma_y-2] = 0;
    if(ma_y>=2) dp[ma_x+1][ma_y-2] = 0;
    if(ma_y>=1) dp[ma_x+2][ma_y-1] = 0;

    for(int i = 0; i <= end_x; i++)
    for(int j = 0; j <= end_y; j++)
    {
        if(!dp[i][j]) continue;
        if(i == 0 && j == 0) continue;
        else if(i == 0) dp[i][j] = dp[i][j-1];
        else if(j == 0) dp[i][j] = dp[i-1][j];
        else
        dp[i][j] = dp[i-1][j]+dp[i][j-1];
    }


    cout<<dp[end_x][end_y]<<endl;
    return 0;
}
