/*************************************************************************
	> File Name: 1002_2.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2015年12月08日 星期二 14时17分49秒
 ************************************************************************/

#include<stdio.h>
#include<iostream>
using namespace std;

int a[1000][1000];
int n;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
            scanf("%d", &a[i][j]);
    }

    for(int i = n-1; i >= 0; i--)
    {
        for(int j = 0; j <= i; j++)
        {
            //a[i][j] = a[i][j] + (a[i+1][j] > a[i+1][j+1] ? a[i+1][j] : a[i+1][j+1]);
            a[i][j] = a[i][j] + max(a[i+1][j] , a[i+1][j+1] );
        }
    }
    printf("%d", a[0][0]);
}
