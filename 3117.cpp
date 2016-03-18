/*************************************************************************
	> File Name: 3117.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月02日 星期三 15时28分58秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;

char a[600];
char b[600];
char c[6000];

int main()
{
    char t[600];
    int f1 = 0, f2 = 0;

    memset(t, 0, sizeof(t));
    cin>>t;
    if(t[0] == '-') f1 = 1;

    int len_t = strlen(t);
    for(int i = 0; i < len_t - f1; i++)
    {
        a[i] = t[len_t - i - 1] - '0';
    }

    memset(t, 0, sizeof(t));
    cin>>t;
    if(t[0] == '-') f2 = 1;

    len_t = strlen(t);
    for(int i = 0; i < len_t - f2; i++)
    {
        b[i] = t[len_t - i - 1 ] - '0';
    }
    int flag = f1 * f2;
/*
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<flag<<endl;
*/
    for(int i = 0; i < 600; i++)
    {
        for(int j = 0; j < 600; j++)
        {
            c[i+j] += a[i] * b[j];  //注意细节，这里是加等，不是等

            if(c[i+j] >= 10 )
            {
               // printf("jinwei: %d\n", c[i+j] / 10);
                c[i+j+1] += c[i+j] / 10;
                c[i+j] %= 10;
            }
        }
    }
    if( f1 ^ f2 ) printf("-");
    
    int i;
    for( i = 0; i < 2000; i++)
    {
        if(c[2000 - i] != 0) break;
    }
    
    while(2000 - i >= 0){
        printf("%d", c[2000 - i]);
        i++;
    }
     
}
