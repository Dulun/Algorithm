/*************************************************************************
	> File Name: 1029.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月17日 星期四 17时42分08秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50086;
char a[N];
char b[N];
 
int main()
{
    scanf("%s%s",a, b);
    int l1 = strlen(a);
    int l2 = strlen(b);
    int sum = 0;
    for(int i = 1; i < l1; i++)
    for(int j = 1; j < l2; j++)
    {
        if(a[i-1] == b[j] && a[i] == b[j-1])
            sum++;
    }
    int ans = 1<<sum;
    cout<<ans<<endl;
 
    return 0;
}
