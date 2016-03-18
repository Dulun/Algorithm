/*************************************************************************
	> File Name: hdu_1358_kmp循环节.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月14日 星期一 17时00分11秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 1e6+9;
int nxt[N];
char a[N];
int cnt = 0;

void getnxt()
{
    int k = 0;
    int len = strlen(a);
    for(int i = 1; i < len ; i++)
    {
        while(k && a[k] != a[i]) k = nxt[k-1];
        if(a[k] == a[i]) k++;
        nxt[i] = k;
    }
}


void sovle()
{
    getnxt();
    int n = strlen(a);
    printf("Test case #%d\n", ++cnt);
    for(int i = 1; i < n; i++)
    {
        int t = (i+1) - nxt[i];
        if( nxt[i] == 0 ) continue;
        if((i+1) % t == 0) 
        {
            printf("%d %d\n", i+1, (i+1) / t );
        }
    }
    printf("\n");
}

int main()
{
    int n;
    while(~scanf("%d", &n) && n)
    {
        int n;
        scanf("%d", &n);
        scanf("%s", a);
        sovle();
    }
 
    return 0;
}
