/*************************************************************************
	> File Name: 1098_t.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月17日 星期四 15时14分31秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50086;
int a[N];

int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum+=a[i];
    }
    int ave = sum / n;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] != ave)
        {
            ans++;
            a[i+1] += a[i] - ave;
        }
    }
    printf("%d\n", ans);
 
    return 0;
}
