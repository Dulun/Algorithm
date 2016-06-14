/*************************************************************************
        > File Name: 1792.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年06月14日 星期二 21时12分31秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 50086;

LL a[N];

int main()
{
    LL n;
    cin >> n;

    cout << n << "=";
    int x = 2;
    while(n != 1)
    {
        if(n % x == 0 && n / x != 1 )
        {
            n /= x;
            cout << x << "*";
        }

        if(n % x == 0 && n / x == 1) n /= x , cout << x;
        if(n % x != 0) x++;
    }
    return 0;
}
