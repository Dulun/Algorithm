/*************************************************************************
	> File Name: hdu_2087.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月14日 星期一 14时07分23秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50086;
char a[1009];
char b[1009];
int nxt[1009];

void getnxt()
{
    int len = strlen(b);
    int k = 0; 
    memset(nxt, 0, sizeof(nxt));
    for(int i = 1; i < len; i++)
    {
        while(k && b[i] != b[k]) k = nxt[k-1];
        if(b[i] == b[k]) k++;
        nxt[i] = k;
    }
}

int kmp()
{
    int j = 0;
    getnxt();
    int len = strlen(a);
    int count = 0;

    for(int i = 0; i < len; i++)
    {
        while(j && a[i] != b[j]) j = nxt[j-1];
        if(a[i] == b[j]) j++;
        if(j == strlen(b)) count++, j = 0;
    }
    return count;
}

int main()
{
    while(~scanf("%s", a) && a[0] != '#')
    {
        scanf("%s", b);
        printf("%d\n", kmp());
    }
 
    return 0;
}
