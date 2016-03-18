/*************************************************************************
	> File Name: 4.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月17日 星期四 13时30分54秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50086;
char a[N];
char b[N];
int ans;
int l1, l2;

void dfs(int i, int j, int sum)
{

    if(i >= l1 && j >= l1)
    {
        if(sum < ans) ans = sum;
        return;
    }

    if(a[i] == b[j])
    {
        dfs(i+1, j+1, sum);
    }

    if(a[i] != b[j])
    {
        //漏掉
        if(i < l1)
        dfs(i+1, j, sum+1);
        //错码
        if(i+1 < l1 && j+1 < l2)
        dfs(i+1, j+1, sum+1);
        //重副
        if(j < l2)
        dfs(i, j+1, sum+1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s%s", a, b);
        l1 = strlen(a);
        l2 = strlen(b);
        ans = 1<<20;
        dfs(0, 0, 0);
        printf("%d\n", ans);
        memset(b, 0, sizeof(b));
        memset(a, 0, sizeof(a));
    }
 
    return 0;
}
