/*************************************************************************
	> File Name: 1022_石子归并v2.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月07日 星期一 13时33分38秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 2086;
int a[N];
int dp[N][N];
int sum[N];
 
int main()
{
    int n; 
    cin>>n;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if(i)sum[i] = sum[i-1]+a[i];
        else sum[i] = a[i];
    }
    for(int i = n; i < 2*n; i++)
    {
        a[i] = a[i-n];
        sum[i] = sum[i-1]+a[i];
    }

    for(int len = 2; len <= n; len++)
    {
        for(int start = 0; start < 2*n - len + 1; start++)
        {
            int mi = 1<<30;
            int end = start+len-1;
            for(int k = start; k < end; k++ )
            {
                mi = min(mi, dp[start][k]+dp[k+1][end] + sum[end] - sum[start-1]);
            }
            dp[start][end] = mi;
           // printf("dp[%d][%d] = %d\n", start, end, mi);
        }
    }
    int ans = 1<<30;
    for(int i = 0; i < n; i++)
    {
        ans = min(ans, dp[i][i+n-1]);
    }
    cout<<ans<<endl;

}

/*#include <cstdio>  
#include <iostream>  
#include <cstring>  
using namespace std;  
#define LL int  
#define inf 1<<30  
#define min(a,b) ((a)<(b)?(a):(b))  
LL dp[2002][2002];  
LL s[2002][2002];  
LL p[2002];  
LL w[2002][2002];  
int main()  
{  
    int n;  
    while(~scanf("%d",&n))  
    {  

        for(int i=1;i<=n;++i)  
        {  
            scanf("%d",&p[i]);  
            p[i+n]=p[i];  
        }  
        memset(s,0,sizeof(s));  
        memset(w,0,sizeof(w));  
        for(int i=1;i<2*n;++i)  
        {  
            for(int j=i;j<=i+n;++j)  
            {  
                w[i][j]=w[i][j-1]+p[j];  
            }  
            s[i][i]=i;  
            dp[i][i]=0;  
        }  

        for(int len=2;len<=n;++len)  
        {  
            for(int i=1;i<=2*n-len+1;++i)  
            {  
                int j=i+len-1;  
                dp[i][j]=inf;  
                for(int k=s[i][j-1];k<=s[i+1][j];++k)  
                {  
                    LL tmp=dp[i][k]+dp[k+1][j]+w[i][j];  
                    if(tmp<dp[i][j])  
                    {  
                        dp[i][j]=tmp;  
                        s[i][j]=k;  
                    }  
                }  
            }  
        }  

        LL ans=inf;  
        for(int i=1;i<=n;++i)  
        {  
            ans=min(ans,dp[i][i+n-1]);  
        }  
        printf("%d\n",ans);  
    }  
    return 0;  
}*/
