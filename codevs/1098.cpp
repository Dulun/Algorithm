/*************************************************************************
	> File Name: 1098.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2015年12月01日 星期二 18时11分05秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int n, a[101];
    int sum = 0, arv, cnt = 0;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }

    arv = sum / n;
    for(int i = 0; i < n; i++)
    {
        if(a[i] != arv)
        {
            cnt++;
            a[i+1] += a[i] - arv;
        }
    }
    cout<<cnt;
    return 0;
}
