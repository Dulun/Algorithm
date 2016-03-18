/*************************************************************************
	> File Name: 全排列.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月04日 星期五 14时13分59秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<unistd.h>
#define LL long long
using namespace std;
 
const int N = 10;
int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void print(int n, int cur)
{
    if(n == cur)
    {
        for(int i = 0; i < n; i++){
            printf("%d ", a[i]);
        }
        printf("\n");
        sleep(1);
    }
    else for(int i = 1; i <= n; i++)
    {
        int ok = 1;
        for(int j = 0; j < cur; j++)
            if(a[j] == i) ok = 0;
        if(ok)
        {
            a[cur] = i;
            print(n, cur+1);
        }
    }
}

int main()
{
    print(10, 0);
     
    return 0;
}
