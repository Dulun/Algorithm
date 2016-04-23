/*************************************************************************
        > File Name: e.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月20日 星期三 14时36分19秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 500086;
char m[N], n[N], ans[N];
int h[200];


int main()
{
	while(~scanf("%s%s", m, n))
	{
		memset(h, 0, sizeof(h));
		memset(ans, 0, sizeof(ans));

		int l_n = strlen(n);
		for(int i = 0; i < l_n; i++)
		{
			h[n[i]]++;
		}
		int l_m = strlen(m);
		int cnt = 0;

		for(int i = 0; i < l_m; i++)
		{
			if(h[m[i]] == 0) ans[cnt++] = m[i];
		}
		if(cnt == 0)
		{
			printf("EMPTY\n");
		}
		else{
			printf("%s\n", ans);
		}

	}

    return 0;
}
