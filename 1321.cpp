/*************************************************************************
	> File Name: 1321.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年01月16日 星期六 23时15分27秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

bool list[10] = {0};

int n, k, count, num;
int chess[10][10] = {0};

void init()
{
    for(int j = 0; j < n; j++) list[j] = 0;
}

void dfs(int index)
{
    if(k == num) {count ++; return ;}
    if(index >= n) return;

    for(int i = 0; i < n; i++)
    {
        if(chess[index][i] == 1 && list[i] == 0)
        {
            list[i] = 1;
            num++;
            dfs(index+1);
            list[i] = 0;
            num--;
        }
    }
    dfs(index+1);
}

int main()
{
    int cnt = 0;
    int ans[100];
    while(cin>>n>>k)
    {
        count = 0;
        if(n == k && k == -1) break;
        
        char ch;
        init();
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            cin>>ch;
            if(ch == '#') chess[i][j] = 1;
            if(ch == '.') chess[i][j] = -1;
        }
        dfs(0);
        ans[cnt++] = count;
    }
    for(int i = 0; i < cnt; i++) 
    printf("%d\n", ans[i]);

    return 0;
}
