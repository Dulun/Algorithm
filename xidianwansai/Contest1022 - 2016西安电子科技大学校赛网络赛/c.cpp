/*************************************************************************
        > File Name: c.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月20日 星期三 13时04分24秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 50086;
int nxt[10];
char a[101][N];
char p[10] = "wanshen";
int n;
int l = strlen(p);
void init()
{
	int k = 0;
	nxt[0] = 0;
	for(int i = 1; i < l; i++)
	{
		while(k && p[i] != p[k]) k = nxt[k-1];
		if(p[i] == p[k]) k++;
		nxt[i] = k;
	}
}

int kmp()
{
	int ans = 0;
	int k = 0;
	for(int i = 0; i < n; i++)
	{
		int len = strlen(a[i]);
		for(int j = 0; j < len; j++)
		{
			while(k && a[i][j] != p[k]) k = nxt[k-1];
			if(p[k] == a[i][j]) k++;
			if(k == l)
			{
				ans++;
				k = 0;
			}
		}
	}
	return ans;
}

int main()
{
	init();
	while(cin>>n)
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%s", a[i]);
		}
		printf("%d\n", kmp());
	}
    return 0;
}
