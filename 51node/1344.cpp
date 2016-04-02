/*************************************************************************
	> File Name: 1344.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年04月02日 星期六 14时04分51秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50086;
int a[N]; 
int main()
{
    int n;
    scanf("%d", &n);

    LL total = 0;
    LL ans = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        total += a[i];
        if(total  < 0){
            ans += total;
            total = 0;
        }   
    }
    printf("%lld\n", -ans);



    return 0;
}
