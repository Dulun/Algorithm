/*************************************************************************
        > File Name: g.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月21日 星期四 12时53分26秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 999909;
LL a[N+N];

int main()
{
	int n, k;
	while(cin>>n>>k)
	{
		memset(a, 0, sizeof(a));
		for(int i = 0; i < n; i++)
			scanf("%lld", &a[i]);

		if(n == 1)
		{
			printf("%lld\n", a[0]);
			continue;
		}

		if(k != 2)
		{
			while(n % (k-1) != 1)
			a[n++] = 0;
		}

		sort(a, a+n);
		int m = 0;
		LL ans = 0;
		while(m <= n-k)
		{
			for(int i = 0; i < k-1; i++)
			{
				a[m+k-1] += a[i+m];
			}
			ans += a[m+k-1];
			m += k-1;
			sort(a, a+n);
		}
		cout<<ans<<endl;
	}
    return 0;
}
