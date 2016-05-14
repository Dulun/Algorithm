/*************************************************************************
        > File Name: 1205.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年05月14日 星期六 20时01分39秒
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
    int k = 0;
    string a[N];
    while(cin>>a[k])
    {
        k++;
    }
    for(int i = k-1; i >= 0; i--)
    {
        cout<<a[i]<<" ";
    }

 
    return 0;
}
