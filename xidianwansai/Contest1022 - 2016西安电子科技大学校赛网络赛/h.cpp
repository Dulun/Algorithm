
/**********************
        > File Name: g.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月21日 星期三 11时23分13秒
 **************************/
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 500086;
const LL MAX_N = 5;
const LL MOD = 1000000007;

LL N;

void mult( LL a[MAX_N][MAX_N], LL b[MAX_N][MAX_N], LL c[MAX_N][MAX_N] )
{
    for( LL i = 1; i <= 4; i++ )
	{
        for( LL j = 1; j <= 4; j++ )
		{
            c[i][j] = 0;
            for( LL k = 1; k <= 4; k++ )
			{
                c[i][j] = ( c[i][j] + a[i][k] * b[k][j] % MOD ) % MOD;
            }
        }
    }
}

void s_pow( LL a[MAX_N][MAX_N], LL n )
{//矩阵快速幂
    LL ans[MAX_N][MAX_N] = {0};
    LL temp[MAX_N][MAX_N];
    for( LL i = 1; i <= 4; i++ )   ans[i][i] = 1;

    while( n )
	{
        if( n % 2 == 1 )
		{
            mult( ans, a, temp );
            memcpy( ans, temp, sizeof( LL ) * MAX_N * MAX_N );
        }
        mult( a, a, temp );
        memcpy( a, temp, sizeof( LL ) * MAX_N * MAX_N );
        n /= 2;
    }
    memcpy( a, ans, sizeof( LL ) * MAX_N * MAX_N );
}

LL fuk( LL n )
{
    LL a[MAX_N][MAX_N] = {0};
    if( n < 0 )
	{
        return 0;
    }
    if( n == 0 )
	{
        return 1;
    }
	else if( n == 1 )
	{
        return 2;
    }

    a[1][1] = 0;a[1][2] = 1;a[1][3] = 0;a[1][4] = 0;
    a[2][1] = 0;a[2][2] = 0;a[2][3] = 1;a[2][4] = 0;
    a[3][1] = 1;a[3][2] = 1;a[3][3] = 1;a[3][4] = 0;
    a[4][1] = 0;a[4][2] = 0;a[4][3] = 1;a[4][4] = 1;
    s_pow( a, n - 1 );
    LL ans = 0;
    LL b[MAX_N];
    b[1] = b[2] = b[3] = 1;
    b[4] = 2;
    for( LL i = 1; i <= 4; i++ )
	{
        ans = ( ans + a[4][i] * b[i] % MOD ) % MOD;
    }
    return ans;
}

int main()
{
    LL A, B;
    while( scanf( "%lld%lld", &A, &B ) != EOF )
	{
        printf( "%lld\n", ( fuk( B ) - fuk( A - 1 ) + MOD ) % MOD );
    }

    return 0;
}
