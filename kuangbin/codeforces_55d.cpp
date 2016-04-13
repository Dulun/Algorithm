/*************************************************************************
        > File Name: codeforces_55d.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月12日 星期二 11时01分12秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
const int N = 150086;
char a[N];
char t[N*2];
int r[N*2];

void change()
{
	int len = strlen(a);
	t[0] = '@';
	t[1] = '#';
	for(int i = 0; i < len ;i++)
	{
		t[2*i+2] = a[i];
		t[2*i+3] = '#';
	}
	t[len*2+1] = '#';
	t[len*2+2] = '\0';
}

int manacher()
{
	memset(r, 0, sizeof(r));
	int len = strlen(t);
	int ans = 1;
	int mid = 1;
	r[0] = r[1] = 1;
	for(int i = 2; i <= len; i++)
	{
		int num = min(r[2*mid-i], r[mid] + mid -i);
		while(t[i+num] == t[i-num]) num++;
		r[i] = num;
		if(i+r[i] > mid+r[mid]) mid = i;
		if(num > ans) ans = r[i];
	}
	return ans-1;
}

int main()
{
	while(~scanf("%s", a))
	{
		change();
		//printf("%s\n", t);
		printf("%d\n", manacher());
	}

    return 0;
}
