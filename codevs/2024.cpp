/*************************************************************************
	> File Name: 2024.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月17日 星期二 19时51分35秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
    char a[1000];
    char b[1000];
    char tmp[1000];
    cin>>a>>b;
    char t;
    int len_a = strlen(a);
    int len_b = strlen(b);
    int flag = 0;
    int sum;

//将a，b  置为一长一短

    if(len_a < len_b)
    {
        strcpy(tmp, a);
        strcpy(a, b);
        strcpy(b, tmp);
        
    }
    len_a = strlen(a);
    len_b = strlen(b);
//----------翻转--------------------------------------
    for(int i = 0,j = len_a - 1; i < j; i++,j--)
    {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    for(int i = 0,j = len_b - 1; i < j; i++,j--)
    {
        t = b[i];
        b[i] = b[j];
        b[j] = t;
    }
    int i;
 //   cout<<a<<" "<<b<<endl;
    flag = 0;
    for(i = 0; i < len_a; i++)
    {
        if(i < len_b)
            sum = a[i] + b[i] -'0' -'0' + flag;
        if(i >= len_b)
        {
            sum = a[i] + flag - '0';
        }
     //   cout<<sum<<endl;
        if(sum < 10)
        {
            a[i] = sum + '0';   
            flag = 0;
        }
        if(sum >= 10)
        {
            flag = 1;
            a[i] = sum - 10 + '0';
        }
    }
  //  cout<<a<<endl;

    if(flag == 1)
    {
        a[i] = 1+'0';
        a[i+1] = '\0';
    }
    
    for(int i = 0,j = strlen(a) - 1; i < j; i++,j--)
    {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    cout<<a<<endl;

}
