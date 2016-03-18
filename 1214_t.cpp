/*************************************************************************
	> File Name: 1214_t.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月17日 星期四 20时06分07秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50086;
 
struct Node 
{
    int l, r;
};
Node a[N];
bool cmp(Node a, Node b)
{
    return a.r < b.r;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d", &a[i].r, &a[i].l);
        if(a[i].l > a[i].r)
        swap(a[i].l, a[i].r);
    }
    sort(a, a+n, cmp);

    int ans = 1;
    int cnt = a[0].r;
    for(int i = 1; i < n; i++)
    {
        if(a[i].l >= cnt)
        {
            cnt = a[i].r;
            ++ans;
        }
    }
    
    cout<<ans<<endl;
    return 0;
}
