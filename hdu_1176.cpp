/*************************************************************************
	> File Name: hdu_1176.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月12日 星期六 22时43分50秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50086;

void getnext()
{
    int j = 0, k = -1;
    while(j < m)
    {
        if(k == -1 || b[k] == b[j])
        {
            j++, k++;
            if(b[k] == b[j]) next[j] = next[k];
            else next[j] = k;
        }
        else k = next[k];
    }
}
int kmp()
{
    int i = 0, j = 0;
    while(i < n && j < m)
    {
        if(j == -1 || a[i] == b[j]) i++, j++;
        else j = next[j];
    }
    if(j > m) return i-m;
    else return -1;
}

int main()
{
 
    return 0;
}
