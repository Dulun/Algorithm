/*************************************************************************
	> File Name: prev_2.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月14日 星期一 20时41分50秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 506;
char a[N][N]; 
int n;

void print()
{
    int m = 4*n+5;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
}

void make()
{
    
    int m = 4*n+5;

    for(int i = 0; i < m; i++)
    for(int j = 0; j < m; j++) 
    {
        a[i][j] = '.';
    } 

    
    for(int ceng = 1; ceng <= n; ceng++)
    {
       
        for(int i = 2*ceng; i < m - 2*ceng; i++ )
        {//上下
            a[2*(ceng-1)][i] = '$';
            a[m-1-(ceng-1)*2][i] = '$';
        }
        for(int i = (ceng)*2; i < m - 2*ceng; i++)
        {//左右
            a[i][(ceng-1)*2] = '$';
            a[i][m-1-(ceng-1)*2] = '$';
        }
        
        for(int i = (ceng-1)*2; i < (ceng-1)*2+3; i++)
        {
            a[i][2*ceng] = '$';
            a[i][m-2*ceng-1] = '$';//
        }
        for(int i = m-1-(ceng-1)*2-2; i < m-1-(ceng-1)*2+1; i++ )
        {
            a[i][2*ceng] = '$';
            a[i][m-2*ceng-1] = '$';
        }
        
        for(int i = (ceng-1)*2; i < (ceng-1)*2+3; i++)
        {
            a[2*ceng][i] = '$';
           // a[2*ceng][i+m-2*ceng] = '$';//
        }
        for(int i = 0; i < 3; i++)
        {//第二天改的，第一天在一个循环中，闷了很久，今天索性重另开循环新打印吧
            a[2*ceng][i+m-1-2*ceng] = '$';
        }

        for(int i = (ceng-1)*2; i < (ceng-1)*2+3; i++)
        {
            a[m-ceng*2-1][i] = '$';
           // a[m-ceng*2-1][m-2*ceng-3+i-1] = '$';这句死活没对，也不想改了，另开一重循环，单独打印这条线，就是右下部分一条短线
        }
        for(int i = 0; i < 3; i++)
        {
            a[m-ceng*2-1][m-1-2*ceng+i] = '$';
        }
    }
    for(int i = 0; i < 5; i++) //最后中间十字
    {
        int k = (m+1)/2-1;
        a[k][2*n+i] = '$';
        a[2*n+i][k] = '$';
    }
}

 
int main()
{
    scanf("%d", &n);
    make();
    print();
 
    return 0;
}
