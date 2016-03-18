/*************************************************************************
	> File Name: 1978.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月12日 星期六 21时23分48秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50086;
int l[80];

int f(int n)
{
    if( n == 1 ) return l[1] = 1;
    if(n == 0) return l[0] = 0;
    if(l[n] > 0) return l[n];
    return l[n] = f(n-1) + f(n-2);
}

int main()
{
    int n;
    cin>>n;
    cout<<f(n)<<endl;

    return 0;
}
