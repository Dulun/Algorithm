/*************************************************************************
	> File Name: 单增子序列2.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年02月29日 星期一 19时16分10秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int a[50008];
int dp[50008];
int pre[50008];
 
int main()
{
    int i, j, k,r, l, m, len = 1, n;
    cin>>n;
    for(int i = 0 ; i < n; i++)
    {
        cin>>a[i];
        pre[i] = i;
    }

    dp[0] = a[0];

    for(int i = 1; i < n; i++)
    {
        l = 0; r = len;
        while( l < r )
        {
            m = (l+r) / 2;
            if(dp[m] < a[i]) l = m+1;
            else             r = m;
        }
        dp[l] = a[i];
        if(l == len) len++;
        pre[len] = a[i];
    }
    printf("%d\n", len);
    return 0;

}
