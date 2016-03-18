/*************************************************************************
	> File Name: 1085_second.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月18日 星期五 13时20分34秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50086;
int dp[N];

int main()
{
    int n, W;
    scanf("%d%d", &n, &W);
    int maxx = 0;

    for(int i = 1; i <= n; i++)
    {
        int w, p, c;
        cin>>w>>p>>c;
       
        for(int k = 1; k <= c; c-=k, k<<=1)
        for(int j = W; j >= w*k; j--)
        {
            dp[j] = max(dp[j], dp[j-w*k]+p*k);
        }
        for(int j = W; j>= w*c; j--) dp[j] = max(dp[j], dp[j-w*c]+c*p);
    }
    
    cout<<dp[W]<<endl;
    return 0;
}
