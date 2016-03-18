/*************************************************************************
	> File Name: 1001.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2015年12月06日 星期日 18时55分31秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int a[50008];

int main()
{
    int k, n;
    cin>>k>>n;
    
    for(int i = 0; i < n; i++) cin>>a[i];

    sort(a, a+n);
    int flag = 0;
    int i = 0, j = n - 1;
    while( i < j )
    {
        if(a[i] + a[j] == k)
        {
            flag = 1;
            cout<<a[i++]<<" "<<a[j--]<<endl;
        }
        if(a[i] + a[j] < k)
        {
            i++;
        }
        if(a[i] + a[j] > k)
        {
            j--;
        }
    }
    if(flag == 0) cout<<"No Solution"<<endl;
    return 0;
}
