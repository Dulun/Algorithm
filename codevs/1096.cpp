/*************************************************************************
	> File Name: 1096.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月11日 星期五 22时22分30秒
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

int main()
{
    for(int i = 1; i <= 10; i++)
    {
        scanf("%d", &a[i]);
    }
    int h;
    cin>>h;
    h+=30;
    int ans = 0;
    for(int i = 1; i <= 10; i++)
    {
        if(a[i] <= h) ans++;
    }
    cout<<ans;
    return 0;
}
