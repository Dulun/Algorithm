/*************************************************************************
	> File Name: prev_29_斐波那契.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月15日 星期二 13时41分16秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 5000086;
LL dp[N] = {0};

LL n,m, p;

LL f(int n)
{
    if(dp[n] > 0 || n == 0) return dp[n];
    else return dp[n] = (f(n-2) + f(n-1)) ;
}
 
int main()
{
    dp[1] = 1;
    dp[2] = 1;
 // 测试
 // cout<<f(300000)<<endl;
    cin>>n>>m>>p;
    LL sum = 0; 
    LL k = f(m);
    for(int i = 1; i <= n; i++) sum += f(i)%p ;

    cout<<sum % k<<endl;
 
    return 0;
}
