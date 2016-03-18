/*************************************************************************
	> File Name: juzhen.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月03日 星期四 13时28分50秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
 
const int N = 506;
 
int a[N][N];
int dp[N];
long long  c[N];

int main()
{
    int m, n;//列，行
    scanf("%d%d", &m, &n);

    long long ans = 0, max = 0;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) scanf("%d", &a[i][j]);

    for(int i = 0; i < m ;i ++)
    {
        for(int j = i; j < m; j++)
        {
            ans = 0;
            for(int k = 0; k < n; k++)
            {
                c[k] = (j == i) ? a[k][i] : c[k] + a[k][j];
                if(ans + c[k] < 0) ans = 0;
                else               ans += c[k];
                if(ans > max) max = ans;
            }
        }
    }
    cout<<max;
    return 0;
}
