/*************************************************************************
	> File Name: 1576.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年02月29日 星期一 21时35分57秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int a[800008];
int dp[800008];

int main()
{
    int n;
    cin>>n;
    int max = 1;

    dp[0] = 1;
    for(int i = 0; i < n; i++) cin>>a[i];

    for(int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(a[j] < a[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j]+1;
        }
            if(dp[i] > max) max = dp[i];
    }
    cout<<max;
    return 0;
}
