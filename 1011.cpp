/*************************************************************************
	> File Name: 1011.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2015年12月13日 星期日 18时49分29秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;


int f(int a, int b)
{
    int r = a % b;
    while(r)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;

}

int main()
{
    int a, b;
    cin>>a>>b;

    cout<<f(a, b);
}
