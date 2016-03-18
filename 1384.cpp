/*************************************************************************
	> File Name: 1384.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月04日 星期五 13时45分52秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 11;



char s[N];
int a[N];
int p[N];
int list[N];

void print(int n, int cnt)
{
    if(n == cnt)
    {
        for(int i = 0; i < n; i++) printf("%d", a[i]);
        printf("\n");
    }
    else{
        for(int i = 0; i < n; i++)
        if(!i || p[i] != p[i-1])
        {
            int c1 = 0, c2 = 0;
            for(int j = 0; j < cnt; j++) if(a[j] == p[i]) c1++;
            if(c1 < list[p[i]])
            {
                a[cnt] = p[i];
                print(n, cnt+1);
            }
        }
    }
}

int main()
{
    cin>>s;
    int list2[N];
    int l = strlen(s);
    for(int i = 0; i < l; i++)
    {
        p[i] = s[i] - '0';
        list[p[i]] += 1;
    }

    sort(p, p+l);

    print(l, 0);
    return 0;
}
