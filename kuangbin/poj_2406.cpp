/*************************************************************************
	> File Name: poj_2406.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月16日 星期三 13时19分57秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 1000086;
char a[N];
int nxt[N];

void getnxt()
{
    int m = strlen(a);
    int k = 0; 
    memset(nxt, 0, sizeof(nxt));

    for(int i = 1; i < m ; i++)
    {
        while(k&& a[k] != a[i]) k = nxt[k-1];
        if(a[k] == a[i]) k++;
        nxt[i] = k;
    }
}

 
int main()
{
    while(~scanf("%s", a) && a[0] != '.')
    {
        getnxt();
        int m = strlen(a);
        int t = m - nxt[m-1];
        if( m % t == 0)
            printf("%d\n", m / t);
        else
            printf("1\n");
        memset(a, 0, sizeof(0));
    }
 
    return 0;
}
