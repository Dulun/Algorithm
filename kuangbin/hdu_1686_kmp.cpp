/*************************************************************************
	> File Name: hdu_1686_kmp.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月13日 星期日 22时35分44秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50086;
const int M = 1000009;

char a[N];
char b[M];
int nxt[N];

void getnxt(int m)
{
    int k = 0;
    memset(nxt, 0, sizeof(0));

    for(int i = 1; i < m; i++)
    {
        while(k && a[i] != a[k]) k = nxt[k-1];
        if(a[i] == a[k]) k++;
        nxt[i] = k;
    }
}

int kmp()
{
    getnxt(strlen(a));
    int j = 0;
    int len = strlen(b);

    int count = 0;
    for(int i = 0; i < len; i++)
    {
        while(j && b[i] != a[j]) j = nxt[j-1];
        if(b[i] == a[j]) j++;
        if(j == strlen(a) ) count++, j = nxt[j-1];
    }
    return count;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        scanf("%s", a);
        scanf("%s", b);
        printf("%d\n", kmp());
    }
    return 0;
}
