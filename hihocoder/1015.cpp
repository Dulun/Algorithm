/*************************************************************************
        > File Name: 1015.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月10日 星期日 00时03分24秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 1e6+100;
int len_a, len_b;
char a[N];
char b[N];
int nxt[N];

void getnext()
{
	int k = 0;
	for(int i = 1; i < len_a; i++)
	{
		while(k && a[i] != a[k]) k = nxt[k-1];
		if(a[i] == a[k] ) k++;
		nxt[i] = k;
	}
}

int kmp()
{
	int k = 0;
	int ans = 0;
	getnext();
	for(int i = 0; i < len_b; i++)
	{
		while(k && a[k] != b[i]) k = nxt[k-1];
		if(a[k] == b[i]) k++;
		if(k == len_a)
		{
			ans++;
			k = nxt[k-1];
		}
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		memset(nxt, 0, sizeof(nxt));

		cin>>a;
		cin>>b;
		len_a = strlen(a);
		len_b = strlen(b);
		printf("%d\n", kmp());
	}
    return 0;
}
