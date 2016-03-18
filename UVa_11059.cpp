/*************************************************************************
	> File Name: UVa_11059.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月18日 星期五 20时24分10秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50086;
int a[20];
int cnt = 0;
int n;

void f()
{
    LL ans = 0;
    for(int i = 1; i <= n; i++)
    {
        LL sum = 1;
        for(int j = i; j <= n; j++)
        {
            sum *= a[j];
            ans = max(ans, sum);
        }
    }
    printf("Case #%d: The maximum product is %lld.\n\n", ++cnt, ans);
}

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i = 1; i <= n; i++) 
        {
            scanf("%d", &a[i]);
        }
        f();
    }
 
    return 0;
}
