/*************************************************************************
	> File Name: 1202_2.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月04日 星期五 12时04分58秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

LL maxv = 1000000007;

const int N = 100086;
int  f[N];

int main()
{
    int n;
    cin>>n;
    int a, ans = 1;
    for(int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);
        a = f[t];
        f[t] = ans;
        ans = (2*ans - a + maxv) % maxv;
    }

    printf("%lld", (ans - 1 + maxv) % maxv);
 
    return 0;
}
