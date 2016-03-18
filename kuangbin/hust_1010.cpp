/*************************************************************************
	> File Name: hust_1010.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月15日 星期二 21时02分30秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50086;
int nxt[1000006];
char a[1000006];

void getnxt(int m)
{
    int k = 0;
    for(int i = 1; i < m; i++)
    {
        while(k && a[i] != a[k]) k = nxt[k-1];
        if(a[i] == a[k]) k++;
        nxt[i] = k;
    }
}
 
int main()
{
 
    while(~scanf("%s", a))
    {
       // cout<<"3452345234";
        memset(nxt, 0, sizeof(nxt));
        int m = strlen(a);
        getnxt(m);
        cout<<m-nxt[strlen(a)-1]<<endl;
        memset(a, 0, sizeof(a));
    }
    return 0;
}
