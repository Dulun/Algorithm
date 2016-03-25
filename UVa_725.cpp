/*************************************************************************
	> File Name: UVa_725.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月18日 星期五 20时44分13秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50086;

bool check(int a, int b)
{
    if(b >98765) return 0;
    bool v[15] = {0};
    memset(v, 0, sizeof(v));
    while(a)
    {
        v[a%10] = 1;
        a /= 10;
    }
    while(b)
    {
        v[b%10] = 1;
        b /= 10;
    }
    int sum = 0;
    for(int i = 0; i < 10; i++)
    {
        sum += v[i];
    }

    return (sum == 10);
}
 
int main()
{
    int n;
    while(~scanf("%d", &n) && n)
    {
        int flag = 0;
        for(int i = 1234; i < 50000; i++)
        {
            if(check(i, i*n))
            {
                printf("%05d / %05d = %d\n", i*n, i, n);
                flag++;
            }
        }
        if(flag == 0) printf("There are no solutions for %d.\n", n);
    }

 
    return 0;
}
