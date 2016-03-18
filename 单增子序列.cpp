/*************************************************************************
	> File Name: 单增子序列.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年02月29日 星期一 16时34分11秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int a[50008];
int dp[50008];
int pre[500008]; 

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    int max = 1;
    dp[0] = 1;

//方法一：复杂度：o(n^2)
    for(int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(a[j] < a[i] && dp[j] + 1 > dp[i])///*****
                dp[i] = dp[j] + 1;
            if(dp[i] > max) max = dp[i];
        }
    }
    cout<<max<<endl;

/*
//方法二：
    int len = 1, mid;
    dp[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        left = 0;
        right = len;
        while(left < right)
        {
            mid = (left + right) / 2;
            if(dp[mid] < a[i]) left = mid + 1;
            else right = mid;
        }
        dp[left] = a[i];
        if(left >= len) len++;
    }
    cout<<len;

*/




    return 0;
}
