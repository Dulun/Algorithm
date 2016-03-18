/*************************************************************************
	> File Name: 1384_全排列.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月04日 星期五 15时41分59秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#define LL long long
using namespace std;
const int N = 50;
int a[N];
int p[N];
char s[N];
int visit[N];
int n;

void dfs(int start)
{
    if(start == n)
    {
        printf("%s\n", s);
        return;
    }
     for(int i=start; i<n; i++)
    {
        if(i!=start &&  s[i] == s[start])
            continue;
        swap(s[i], s[start]);
        dfs(start+1);
        swap(s[i], s[start]);
    }
}

int main()
{
    cin>>s;
    n = strlen(s);
    sort(s, s+n);
    dfs(0);
    return 0;
}
