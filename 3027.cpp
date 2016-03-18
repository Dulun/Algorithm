/*************************************************************************
	> File Name: 3027.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月06日 星期日 15时46分36秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50086;
 
struct Line
{
    int a, b, c;
};
Line l[1008];
int dp[1008];
int cmp(Line a, Line b){ return a.b < b.b; }



int main()
{
    int n;
    cin>>n;
    int ans = 0;

    for(int i = 1; i <= n; i++) 
    {
        cin>>l[i].a>>l[i].b>>l[i].c;
    }
    sort(l+1, l+1+n, cmp);
    for(int i = 1; i <=n; i++) dp[i] = l[i].c;

    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(l[j].b <= l[i].a)
                dp[i] = max(dp[i], dp[j] + l[i].c);
        }
    }
    for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    cout<<ans<<endl;
    return 0;
}
