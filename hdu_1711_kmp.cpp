/*************************************************************************
	> File Name: hdu_1711_kmp.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月13日 星期日 17时24分34秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
int m, n;
int a[1000009];
int b[10009];
int nextval[10009];
const int N = 50086;

void getnext()
{
    int k = 0; 
    nextval[0] = 0;
    for(int i = 1; i < m; i++)
    {
        while(k && b[k] != b[i]) k = nextval[k-1];
        if(b[k] == b[i]) k++;
        nextval[i] = k;
    }
}

int kmp()
{
    int j = 0;
    getnext();
    for(int i = 0; i < n; i++)
    {
        while(j && a[i] != b[j]) j = nextval[j-1];
        if(a[i] == b[j]) j++;
        if(j == m) return i-j+1 + 1;
    }
    return -1;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        for(int i = 0; i < m; i++) scanf("%d", &b[i]);
        if(m >n) {printf("-1\n"); continue;}
        printf("%d\n", kmp());
    }
 
    return 0;
}
