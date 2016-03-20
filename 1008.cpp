/*************************************************************************
	> File Name: 1008.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月20日 星期日 15时00分42秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50086;
int a[30];
bool v[30];
int n, k;
int ans = 0;
bool check(int n)
{
    if(n == 1 || n == 0) return 0;
    if(n == 2 || n == 3) return 1;

    for(int i = 2; i*i <= n; i++)
    {
        if(n % i == 0) return 0;
    }
    return 1;
}

void dfs(int s, int cnt, int sum)
{
    if(cnt == k) 
    {
       // printf("%d\n", sum);
        if(check(sum)){ans++;} 
        return;
    }
    int k = 1;   
    for(int i = s; i < n; i++)
    {
        if(!v[i])
        {
            v[i] = 1;
            dfs(s+k, cnt+1, sum+a[i]);
            k++;
            v[i] = 0;
        }
    }
}

int main()
{
    cin>>n>>k;
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i <= n-k; i++)
    {      
        v[i] = 1; 
        dfs(i+1, 1, a[i]);        
    }
    cout<<ans<<endl;
    return 0;
}
