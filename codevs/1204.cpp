/*************************************************************************
        > File Name: 1204.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年05月14日 星期六 20时08分59秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50086;
 
int main()
{
 
    char a[N], b[N];
    scanf("%s%s", a, b);

    int la = strlen(a);
    int lb = strlen(b);


    for(int i = 0; i <= la - lb; i++)
    {
        int k = 0, m = i;
        while(a[m] == b[k])
        {
            m++, k++;
            if(k == lb)
            {
                printf("%d\n", i+1);
                return 0;
            }
        }
    }
    return 0;
}
