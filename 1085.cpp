/*************************************************************************
	> File Name: 1085.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月02日 星期三 17时35分34秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>

using namespace std;

int dp[50008] = {0};
int count = 0;
int w[50086];
int p[50086];
int c[50086];

int main()
{
    int n, W;
    scanf("%d%d", &n, &W);
    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        count++;
        scanf("%d%d%d", &w[count], &p[count], &c[count]);
    }

    for(int i = 1; i <= count; i++)
    {
        for(int k=c[i]; k>0; k--)
            for(int j = W; j >= w[i]; j--)
            {
                dp[j] = max(dp[j], dp[j-w[i]]+p[i]);
                //printf("dp[%d] = %d \n", j, dp[j]);
            }   
    } 

    cout<<dp[W];
}
