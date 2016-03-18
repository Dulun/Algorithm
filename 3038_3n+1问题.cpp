/*************************************************************************
	> File Name: 3038_3n+1问题.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月08日 星期二 21时05分21秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 10086;

int f(int n)
{
    int step = 0;

    while(n!=1)
    {
        step++;
        if(n % 2) n = 3*n+1;
        else n /= 2;
    }
    return step;
}

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        printf("%d\n", f(k));
    }
 
    return 0;
}
