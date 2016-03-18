/*************************************************************************
	> File Name: 1219_骑士游历.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月09日 星期三 21时27分48秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 60;

LL dp[N][N]; //路径太多需要LL

int main()
{
    int n, m;
    cin>>n>>m;
    int x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;
    dp[x1][y1] = 1;
 
    for(int i = 1+x1; i <= x2; i++)
    for(int j = 1; j <= n; j++)
    {
        dp[i][j] = dp[i-1][j+2]+dp[i-1][j-2]+dp[i-2][j+1]+dp[i-2][j-1];
    }
    cout<<dp[x2][y2];
    return 0;
}
