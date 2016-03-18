/*************************************************************************
	> File Name: 1116_四色问题.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月08日 星期二 21时28分18秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

int map[9][9];
int color[9];
int ans = 0;
int n;

void dfs(int k)
{
    int i, j;
    if(k == n+1){
        ans++;
        return ;
    }
    for( i = 1; i <= 4; i++)
    {
        for( j = 1; j < k; j++)
        {
            if(map[k][j] && color[j] == i) break;
        }
        if(j == k)
        {
            color[k] = i;
            dfs(k+1);
            color[k] = 0;
        }
    }
}

int main()
{
    cin>>n;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    scanf("%d", &map[i][j]);
    dfs(1);
    cout<<ans<<endl;
    return 0;

}
