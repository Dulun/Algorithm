/*************************************************************************
	> File Name: 1004.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月31日 星期四 20时27分19秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50086;
int a[N]; 
int main()
{
    int n;
    cin>>n;
    if(n == 0) 
    {
        cout<<"1"<<endl;
        return 0;
    }
    int k = n % 10;
    if(k == 0)
    {
        printf("0\n");
        return 0;
    }

    a[0] = k;
    int cnt = 1;
    while(1)
    {
        a[cnt] = a[cnt-1] * k % 10;
        if(a[cnt] == k) break;
        cnt++;
    }
 
    int p = (n-1) % cnt ; 
    cout<<a[p];
    return 0;
}
