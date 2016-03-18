/*************************************************************************
	> File Name: 1212.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2015年12月03日 星期四 19时03分24秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstdio>
using namespace std;

int a[1009][1009] = {0};
const int maxv = 999999;

int adj[1008];
int low[1008];
int main()
{
    int n, m;
    cin>>n>>m;

    for(int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < n+1; j++)
            a[i][j] = maxv;
    }
    for(int i = 0; i < n+1; i++)
        a[i][i] = 0;

    int x, y,w;
    for(int i = 0; i < m; i++)
    {
        //cin>>x>>y>>w;
        scanf("%d%d%d", &x, &y, &w);
        a[x][y] = w;
        a[y][x] = w;
    }
    

    for(int i = 0; i < n+1; i++)
    {
        low[i] = a[1][i];
        adj[i] = 0;
    }
    low[0] = 0;

    int count = 0;
    int sum = 0;
    int k;
    int min;
    while(count < n-1)
    {
        min = maxv; 
        for(int i = 1; i < n+1; i++)
        {
            if(low[i] < min && low[i] != 0)
            {
                k = i;
                min = low[i];
            }
        }
        
        sum += low[k];
        low[k] = 0;

        for(int i = 1; i < n+1; i++)
        {
            if(low[i] > a[k][i] && low[i] != 0)
            {
                low[i] = a[k][i];
                adj[i] = k;
            }
        }
        count++;
    }

    cout<<sum;
    return 0;

}
