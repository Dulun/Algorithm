/*************************************************************************
	> File Name: 1202.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月03日 星期四 21时22分07秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define LL long long
using namespace std;
 
const int N = 100086;
const int maxv = 1000000000+7;

LL dp[N];
int f[N];
int a[N];

int main()
{
    int n;
    scanf("%d", &n);

    memset(f, 0, sizeof(f));
    for(int i = 1; i <= n; i++ ) scanf("%d", &a[i]);

    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        dp[i] = (dp[i-1] * 2);// % maxv;
        if(f[a[i]] > 0)
        {
            dp[i] = (dp[i] + maxv - dp[f[a[i]] - 1]) % maxv;
        }

        f[a[i]] = i;
    }
    cout<< (dp[n]+maxv-1) % maxv;
    return 0;
}
