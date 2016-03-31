/*************************************************************************
	> File Name: 1003.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月31日 星期四 17时33分17秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 500086;

int main()
{
 
    int n;
    cin>>n;
    int ans = 0;

    while(n >= 5)
    {
        n /= 5;
        ans += n;
    }

    cout<<ans<<endl;

    return 0;
}
