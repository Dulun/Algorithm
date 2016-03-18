/*************************************************************************
	> File Name: 1169.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月09日 星期三 16时35分26秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long 
#define four
//#define three
using namespace std;
 
const int N = 60;
int a[N][N];
#ifdef four
int dp[N][N][N][N];
#endif

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    
    for(int i = 1; i <= m; i++)
    for(int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
 
#ifndef three
    for(int x1 = 1; x1 <= m; x1++)
    for(int y1 = 1; y1 <= n; y1++)
    for(int x2 = 1; x2 <= m; x2++)
    for(int y2 = 1; y2 <= n; y2++)
    {
        if(x1==x2 && y1==y2) continue; 
        int maxv = 0; 
        maxv = max(dp[x1-1][y1][x2-1][y2], max(dp[x1][y1-1][x2-1][y2],  max(dp[x1][y1-1][x2][y2-1], dp[x1-1][y1][x2][y2-1])));
        dp[x1][y1][x2][y2] = a[x1][y1]+a[x2][y2] + maxv;
        //printf("dp[%d][%d][%d][%d] = %d\n", x1, y1, x2, y2, dp[x1][y1][x2][y2]);
    }
    //最后一次 x1 == x2 && y1 == y2
    dp[m][n][m][n] = max(dp[m-1][n][m-1][n], max(dp[m][n-1][m-1][n],  max(dp[m][n-1][m][n-1], dp[m-1][n][m][n-1])));
    cout<<dp[m][n][m][n]<<endl;
#endif

#ifdef three
    //三维dp
    int dp[N+N][N][N];
    for(int k = 1 ; k <= m + n - 1 ; k++ )  
    {  
        int t,s;
        t = ( k > m ) ? m : k ;  
        s = ( k > n ) ? n : k ;  
        for( int x1 = k - s + 1 ; x1 <= t ; x1++ )  
        {  
            for(int x2 = k - s + 1 ; x2 <= t ; x2++ )  
                if( x1 != x2 || k == m + n - 1 )  
                {  
                    int maxv = 0 ;
                    maxv = max(dp[k-1][x1][x2], max(dp[k-1][x1-1][x2], max(dp[k-1][x1][x2-1], dp[k-1][x1-1][x2-1])));
                    dp[k][x1][x2] = maxv + a[x1][k-x1+1]+a[x2][k-x2+1];
                }  
        }   
      
    }
    cout << dp[ m + n - 1 ][ m ][ m ] << endl ;
#endif
    return 0;
}
