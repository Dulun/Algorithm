#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
char s[20];  
int book[30],a[20],ans[20],n;  
  
  
int main()  
{  
    int i,j;  
    cin>>s;  
    n=strlen(s);  
    for(i=0;i<n;i++) a[i]=s[i]-'0';  
    sort(a,a+n);  
    
    do
    {
        for(int i = 0; i < n; i++) cout<<a[i];
        cout<<endl;
    }while(next_permutation(a, a+n));
    
    
    return 0;  
}
