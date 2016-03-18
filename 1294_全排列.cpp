/*************************************************************************
	> File Name: 1294_全排列.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月07日 星期一 21时36分36秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50086;
char n[15];
char a[15];
bool visit[15];
int len;

void print(int cnt)
{
    if(cnt == len) printf("%s\n", a);
    else for(int i = 0; i < len; i++)
    {
        if(!visit[i])
        {
            visit[i] = 1;
            a[cnt] = n[i];
            print(cnt+1);
            visit[i] = 0;
            while(i < len && n[i] == n[i+1]) i++;
        }
    }
}

int main()
{
    cin>>n;
    len = strlen(n);
    sort(n, n+len);

    print(0);
    return 0;
}
