/*************************************************************************
	> File Name: 1126.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年02月29日 星期一 13时19分37秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;
  
int main()
{
    int m, n, count = 0;
    cin>>m>>n;

    for(int i = m; i <= n; i++)
    {
        int t = i;
        while(t > 0)
        {
            int k = t % 10;
            t /= 10;
            if(k == 2) count++;
        }
    }
    cout<<count;
    return 0;
}
