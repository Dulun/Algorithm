/*************************************************************************
	> File Name: 1097_校门外的树.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月11日 星期五 22时13分43秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50086;
int a[10009];

int main()
{
    memset(a, 0, sizeof(a));
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < m; i++)
    {
        int k, t;
        scanf("%d%d", &k, &t);
        for(int j = k ;j <= t; j++)
        {
            a[j]--;
        }
    }

    int ans = 0;
    for(int i = 0; i <= n; i++)
    {
        if(a[i] == 0)  ans++;  
    }
    printf("%d\n", ans);
 
    return 0;
}
