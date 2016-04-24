/*************************************************************************
        > File Name: last.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月23日 星期六 12时55分05秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 50086;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int ans = 0;
		int n;
		scanf("%d", &n);
		ans+=n;
		for(int i = 0; i < n;i++)
		{
			int t;
			scanf("%d", &t);
			ans += t;
		}
		printf("%d\n", ans);
	}

    return 0;
}
