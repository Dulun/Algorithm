/*************************************************************************
	> File Name: hdu_3746_kmp求循环节.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月14日 星期一 14时37分08秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 100009;
char a[N];
int nxt[N];

void getnxt()
{
    memset(nxt, 0, sizeof(nxt));
    int k = 0; 
    int len = strlen(a);
    for(int i = 1; i < len; i++)
    {
        while(k && a[k] != a[i]) k = nxt[k-1];
        if(a[k] == a[i]) k++;
        nxt[i] = k;
    }
}

int main()
{

    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", a);
        getnxt();
        
        int l = strlen(a);
        int xun = l - nxt[l-1];
        if(nxt[l-1] == 0) printf("%d\n", l);
        else if(l % xun == 0) printf("0\n");
        else
        {
            printf("%d\n", xun - l % xun);
        }
    }
 
    return 0;
}
