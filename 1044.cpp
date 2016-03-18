/*************************************************************************
	> File Name: 1044.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月06日 星期日 11时32分05秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 30086;
int a[N];
int dp[N];

int main()
{
    int n = 0;
    while(~scanf("%d", &a[n++])); n--; 
 //   cin>>n;
   // for(int i = 0; i < n; i++) scanf("%d", &a[i]);


    int len = 1;
    dp[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        int left = 0, right = len;
        while(left < right)
        {
            int m = (left+right) / 2;
            if(dp[m] < a[i]) right = m;
            else             left = m+1;
        }
        dp[left] = a[i];
        if(left == len) len++;
    }
    cout<<len<<endl;
 

    len = 1;
    memset(dp, 0, sizeof(dp));
    dp[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        int left = 0, right = len;
        while(left < right)
        {
            int m = (left+right) / 2;
            if(dp[m] > a[i]) right = m;
            else             left = m+1;
        }
        dp[left] = a[i];
        if(left == len) len++;
    }
    cout<<len<<endl;
    return 0;
}
