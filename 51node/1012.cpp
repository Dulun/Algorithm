/*************************************************************************
	> File Name: 1012.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月04日 星期五 12时30分19秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50086;

int gcd(int a, int b)
{
    int r = a % b;

    if(r) return gcd(b, r);
    return b;
}

int main()
{
    int a, b;
    cin>>a>>b;

    int c = gcd(a, b);

    printf("%d\n", c);
    int k = a / c;
    k *= b;
    cout<<k;
 
    return 0;
}
