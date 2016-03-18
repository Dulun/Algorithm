/*************************************************************************
	> File Name: 3115.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月01日 星期二 16时37分49秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

char a[608] = {};
char b[608] = {};
char c[6008] = {};
int flag = 0;

void input()
{
    char t[60000];
    memset(t, 0, sizeof(t));
    cin>>t;

    int f1 = 0;
    if(t[0] == '-') f1 = 1;

    int l1 = strlen(t) ;
    for(int i = 0; i < l1 - f1; i++) a[i] = t[l1 - i - 1] - '0';


    memset(t, 0, sizeof(t));
    cin>>t;
    int f2 = 0;
    if(t[0] == '-') f2 = 1;

    int l2 = strlen(t) ;
    for(int i = 0; i < l2 - f2; i++) b[i] = t[l2 - i - 1] - '0';
    if(f1 == f2) flag = 0;
    if(f1 != f2) flag = 1;
}

void print()
{
    int i;
    for(i = 6000 - 1; i > 0; i--)
    {
        if(c[i] != 0 ) break;
    }

    if(flag == 1 && i != 0)
        printf("-");

    for(; i >= 0; i--)
    {
        printf("%d", c[i]);
    }

}

void imsub()
{

    if(flag == 0)
    {
        for(int i = 0; i < 600 ;i++)
        {
            c[i] = a[i] - b[i]; 
        }
        
    }
    if(flag == 1)
    {
        for(int i = 0; i < 600 ;i++)
        {
            c[i] = b[i] - a[i]; 
        }
    }   

    int l = 0;
    for( l = 6000 - 1; l >=0; l--)
    {
        if(c[l] != 0 ) break;
    }

    if(l == -1) printf("0");

    for(int i = 0; i < l; i++)
    {
        if(c[i] < 0)
        {
            c[i+1] -= 1;
            c[i] += 10 ;
        }
    }
    print();
}

void mult()
{
    int l1 = strlen(a);
    int l2 = strlen(b);

    memset(c, 0, sizeof(c));

    for(int i = 0; i < l1; i++)
    {
        for(int j = 0; j < l2; j++)
        {
            c[i+j] += a[i] * b[j];
            if(c[i+j] >= 10)
            {
                c[i+j+1] += c[i+j] / 10;
                c[i+j] = c[i+j] % 10;
            }
        }
    }
/*
    for(int i = 0; i < 6000; i++)
    {
        if(c[i] >= 10)
        {
            c[i+1] += c[i] / 10;
            c[i] %= 10;
        }
    }
        
*/
    print();
}

int main()
{
    input();
    mult();
}

