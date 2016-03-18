/*************************************************************************
	> File Name: 1002.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2015年12月08日 星期二 13时03分07秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
using namespace std;

int a[1000][1000];
int n;
int s = 0;
int d[1000][1000];

int sovle(int i,  int j)
{
    if(d[i][j] >= 0) return d[i][j];
    return d[i][j] = a[i][j] + (i == n? 0: (sovle(i+1, j) > sovle(i+1, j+1)? sovle(1+i, j):sovle(i+1, j+1)));
}

int main()
{
    memset(d, -1, sizeof(d));
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
            scanf("%d", &a[i][j]);
    }
    
    
    printf("%d", sovle(0, 0));

}

