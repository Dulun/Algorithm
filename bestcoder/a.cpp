/*************************************************************************
        > File Name: a.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月22日 星期五 19时12分33秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 50086;
LL n;
char a[5900] = {0};

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		memset(a, 0, sizeof(a));
		int m;
		LL n;
		scanf("%d%lld", &m, &n);
		int cnt = 0;
		while(n)
		{
			a[cnt++] += n % 3;
			n /= 3;
			if(cnt >m) break;
		}
		for(int i = m-1; i >=0; i--)
		{
			if(a[i] == 0)
				printf("R");
			if(a[i] == 1)
				printf("G");
			if(a[i] == 2)
				printf("B");
		}
		printf("\n");
	}
    return 0;
}
