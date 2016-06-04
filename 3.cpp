/*************************************************************************
        > File Name: 3.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年06月04日 星期六 16时01分24秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#define LL long long
using namespace std;
const int N = 50086;

bool v[6]; 
int a[4] = {0};
int n = 3;
void dfs(int cur, int cnt)
{
    if(cur == n)
    {
        for(int i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    for(int i = cnt; i < 5; i++)
    {
        if(!v[i])
        {
            v[i] = 1;
            a[cur] = i+1;
            dfs(cur+1, i+1);
            v[i] = 0;
        }
    }
}

int main()
{
    dfs(0, 0);
    return 0;
}
