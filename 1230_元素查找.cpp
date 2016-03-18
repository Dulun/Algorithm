/*************************************************************************
	> File Name: 1230_元素查找.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月17日 星期四 14时46分35秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 100086;

int a[N];
int b[N];
 
int main()
{
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        a[t]++;
    }
    for(int i = 0; i < m; i++)
    {
        int t;
        scanf("%d", &t);
        if(a[t] != 0)
        {
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
     
    return 0;
}
