/*************************************************************************
	> File Name: 1078_2.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2015年12月02日 星期三 21时36分41秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int sum = 0;
    int k_v[100] = {0};
    int a[100][100];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"adfasfa";
    int min = 99999999;
    int count = 0;
    int i, j, p, q;
    while(count < n-1)
    {
        min = 99999999;
        for(i = 0; i < n-1; i++)
        {
            for(j = i+1; j < n; j++)
            {
                if(a[i][j] < min && (k_v[i] != 1 || k_v[j] != 1) )
                {
                    min = a[i][j];
                    p = i; q = j;
                }
            }
        }
        
        k_v[p] = 1;
        k_v[q] = 1;
        count ++;
        sum += min;
    }
  
    cout<<sum;
    return 0;
}
