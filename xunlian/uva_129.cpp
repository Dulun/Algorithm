/*************************************************************************
        > File Name: uva_129.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月14日 星期四 14时50分03秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

int n, l;
const int N = 50086;
int a[N];
int s[N];
int cnt = 0;

bool dfs(int cur)
{
	if(cnt++ == n)
	{
		for(int i = 0; i < cur; i++)
		{
			if(i && i % 64 == 0) printf("\n");
			else if(i && i % 4 == 0) printf(" ");
			printf("%c", 'A' + s[i]);
		}
		printf("\n%d\n", cur);
		return 0;
	}

	for(int i = 0; i < l; i++)
	{
		s[cur] = i;
		int ok = 1;
		for(int j = 1; j * 2 <= cur+1; j++)
		{
			int equal = 1;
			for(int k = 0; k < j; k++)
				if(s[cur-k] != s[cur-k-j]) {equal = 0; break;}
			if(equal) {ok = 0; break;}
		}
		if(ok)
		{
			if(!dfs(cur+1)) return 0;
		}
	}
	return 1;
}

int main()
{
	while(~scanf("%d%d", &n, &l) && n+l)
	{
		cnt = 0;
		dfs(0);
	}

    return 0;
}
