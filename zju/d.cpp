/*************************************************************************
        > File Name: d.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月23日 星期六 15时53分37秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
const int N = 50086;
int year, month, day, goal;
//typedef month_N int[15];
int month_N[15];
int month_p[18] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int month_r[18] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void solve()
{
	int k1, k2, k3;
	if(day == 11)
	{
		k1 = 0;
		k2 = 3;
		k3 = 4;
	}
	else if(day == 21){
		k1 = 4;
		k2 = 0;
		k3 = 2;
	}
	else if(day == 1)
	{
		k3 = 0;
		k1 = 3;
		k2 = 6;

	}
	int cnt = 0;
	int now_day;
	int mm[18];

	while(cnt < goal)
	{
		if(k1 == 0 || k2 == 0 || k3 == 0)
		{
			cnt++;
			if(k1 == 0) now_day = 11;
			else if(k2 == 0) now_day = 21;
			else if(k3 == 0) now_day = 1;
		}

		if(month > 12)
		{
			month = 1;
			year++;
		}
		if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			k1+=month_r[month];
			k2+=month_r[month];
			k3+=month_r[month];
		}
		else
		{
			k1+=month_p[month];
			k2+=month_p[month];
			k3+=month_p[month];
		}
		month++;
		k1%=7;
		k2%=7;
		k3%=7;
	}
	month--;
	printf("%d %d %d\n", year, month, now_day);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d%d", &year, &month, &day, &goal);
		solve();
	}

    return 0;
}
