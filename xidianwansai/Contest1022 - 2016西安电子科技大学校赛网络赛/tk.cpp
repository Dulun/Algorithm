/*************************************************************************
        > File Name: tk.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月22日 星期五 00时10分00秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 50086;

int f[100009];

int init()
{
	for(int i=2; i<=100000; i++)
	{
		if(f[i])
			continue;
		for(int j=i+i; j<=100000; j++)
			f[j] = 1;
	}
}

LL fai(LL x)
{

	LL ans = x;
	LL len = x;
	for(int i=2; i<=x && i*i<=len; i++)
	{
		if(f[i])
			continue;
		if(x%i==0)
		{
			ans /= i;
			ans *= i-1;
		}
		while(x%i==0)
			x /= i;
	}
	if(ans == x)
		return ans-1;
	return ans;
}

LL q_power(LL a, LL n, LL mod)
{
	LL ans = 1;
	while(n)
	{
		if(n & 1)
		{
			ans *= a;
			ans %= mod;
		}
		n >>= 1;
		a *= a;
		a %= mod;
	}
	return ans;
}

int main()
{
	init();
	LL a, b, c, d;
	while(cin>>a>>b>>c>>d)
	{
		if(d == 1)
		{
			cout<<"0"<<endl;
			continue;
		}
		LL f = fai(d);
		a %= d;
		LL x = q_power(b, c, f);
		cout<<q_power(a, x, d)<<endl;
	}

    return 0;
}
