/*************************************************************************
        > File Name: d.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月22日 星期五 19时37分23秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

int n;
const int mod = 1e9+7;

int cmn(int m, int n)
{
	printf("--------------%d %d \n", m, n);
	char a;
	cin>>a;
//	printf("ddd\n");
	if(m < n || n < 0) return 0;
	if(m == n || n == 0) return 1;
	return (cmn(m-1, n-1)+cmn(m-1, n)) % mod;
}


void sovle_jishu()
{
	printf("=========\n");
	int ans = 0;

	int k = 2*n-2;
	int p = k;
	printf("%d %d \n", k, p);
	int cnt = (n+1) / 2 -1;
	for(int i = cnt; i >= 0; i++, p--)
		ans = (ans + cmn(k, p)) % mod;

	printf("%d\n", ans);
}
void sovle_oushu()
{

}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		if(n & 1 == 1) sovle_jishu();
		else sovle_oushu();
	}

    return 0;
}
