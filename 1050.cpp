/*************************************************************************
	> File Name: 1050.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月03日 星期四 15时31分07秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

/*“循环数组得最大子段和”问题，可以把环从任意位置断开，
然后求出最优解 = max(普通的最大子段和， 总和 – 普通的“最小子段和”)*/

const int N = 50086;

int a[N]; 

int main()
{
    int n;
    LL ans = 0, t = 0;
    scanf("%d", &n);
    LL sum = 0;

    int flag = 0;
    int f1 = 0;
    for(int i = 0; i < n; i++) 
    {
        scanf("%d",&a[i]);
        sum+=a[i];
        if(a[i] > 0) f1 = 1;
    }
/*
    if(f1 == 0) //全部是负数，输出最大的负数
    {
        int max = a[0];
        for(int i = 0; i < n; i++)
        {
            if(a[i] > max) max = a[i];
        }
        cout<<max;
        return 0;
    }
*/
/*应该是错误思想
    for(int i = 0; i < n; i++)
    {
        if(a[i] < 0) flag = i+1;  //只要a[i] < 0 就有可能从a[i] 断开，进行循环
        if(t + a[i] < 0 ) { t = 0;}
        else              t += a[i];
        if(t > ans) ans = t;
        
        if(i == n-1 )
        {
            for(int j = 0; j < flag; j++)
            {
                if(t + a[j] < 0 ) { t = 0; break;}
                else              t += a[j];
                if(t > ans) ans = t;
                
            }
        }
    }
    cout<<ans;

*/
    //求最小子段
    LL min = a[0];
    t = 0;
    for(int i = 0; i < n; i++)
    {
        if(t + a[i] > 0) t = 0;
        else t += a[i];
        if(min > t) min = t;
    }
    LL ans1 = sum - min;  //求数组和与最小子段相减

    //求最大子段
    t = 0;
    LL ans2 = 0;
    for(int i = 0; i < n; i++)
    {
        if(t + a[i] < 0 ) { t = 0;}
        else              t += a[i];
        if(t > ans2) ans2 = t;
    }
    ans = max(ans1, ans2);
    cout<<ans;


    return 0;
}
