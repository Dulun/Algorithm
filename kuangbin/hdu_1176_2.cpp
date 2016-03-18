/*************************************************************************
	> File Name: hdu_1176.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月04日 星期五 19时13分16秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 100086;

int dp[15][N];
int num[15][N];


int main()
{
    int n, T = 0; 

    while(~scanf("%d", &n) && n){
    int ma = 0;
    memset(dp, 0, sizeof(dp));
    memset(num, 0, sizeof(num));
    for(int i = 0; i < n; i++)
    {
        int point, time;
        scanf("%d%d", &point, &time);
        num[point+1][time]++;
        if(time > T) T = time;
    }

    int i = 5, t = 1;
    for(t = 1; t <= T; t++)
    {
        int l = t < 6? 6-t : 1;
        int r = t < 6? 6+t:11;
        for(int i = l; i <= r; i++)
        {
            dp[i][t] = num[i][t] + max(dp[i][t-1], max(dp[i-1][t-1] , dp[i+1][t-1]));   
        }
        for(int i = 1; i <= 11; i++)
        {
            if(dp[i][T] > ma) ma = dp[i][T];
        }
        
        
    }
 
    cout<<ma<<endl;
    }
    return 0;
}
