/*************************************************************************
	> File Name: UVa_10976.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月19日 星期六 00时45分43秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 1086;

int x[N];
int Y[N];
 
int main()
{
    int k;
    while(~scanf("%d", &k))
    {
        int sum = 0;
        int k2 = k<<1;
        for(int y = k+1; y <= k2; y++)
        {
            if(k * y % (y - k) == 0)
            {
                x[sum] = k*y / (y-k);
                Y[sum] = y;
                sum++;
            }
        }
        printf("%d\n", sum);
        for(int i = 0; i < sum; i++) printf("1/%d = 1/%d + 1/%d\n", k, x[i], Y[i]);
    }
 
    return 0;
}
