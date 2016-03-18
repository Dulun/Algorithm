/*************************************************************************
	> File Name: 1295_N皇后问题.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月09日 星期三 12时23分40秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 20;
int  chess[N];
int ans = 0;
int n;


int check(int x)
{
    int i, j;
    for(i = 1; i < x; i++)
    {
        if(chess[i] == chess[x] || abs(chess[x]-chess[i]) == abs(x-i))
             //不在同一列       或           不在同一对角线
            return 0;
    }
    return 1;
}


void dfs(int x)
{
    if(x == n+1) ans++;
    for(int i = 1; i <= n; i++)
    {
        chess[x] = i;
        if(check(x)) dfs(x+1);
    }
}

 
int main()
{
    scanf("%d", &n);
    dfs(1);
    printf("%d\n", ans);
 
    return 0;
}
