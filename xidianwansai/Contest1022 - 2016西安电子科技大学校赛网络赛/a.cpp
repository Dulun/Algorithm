/*************************************************************************
        > File Name: a.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月20日 星期三 11时51分16秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 50086;

int main()
{
	string z1, z2;
	while(cin>>z1>>z2)
	{
		int a = 0, i;
		for(i = 0; z1[i] != '+'; i++)
		{
			int t = z1[i] - '0';
			a*=10;
			a+=t;
		}
		i++;
		int b = 0;
		for(int j = i; z1[j] != 'i'; j++)
		{
			int t = z1[j] - '0';
			b*=10;
			b+=t;
		}

		int c = 0;
		for(i = 0; z2[i] != '+'; i++)
		{
			int t = z2[i] - '0';
			c*=10;
			c+=t;
		}
		i++;
		int d = 0;
		for(int j = i; z2[j] != 'i'; j++)
		{
			int t = z2[j] - '0';
			d*=10;
			d+=t;
		}

		printf("%d+%di\n", a+c, b+d);

	}

    return 0;
}
