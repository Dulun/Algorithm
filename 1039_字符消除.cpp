/*************************************************************************
	> File Name: 1039_字符消除.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月12日 星期六 13时37分06秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string.h>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;
 
const int N = 50086;

int xiaochu(char * s)
{
    int n = 0;
    char t[109];
    for(int i = 0; i <= strlen(s); i++) t[i] = s[i];

    int flag = 1;
    while(1)
    {
        if(flag == 0) break;
        flag = 0;
        int i, j;
        for(i = 0; i < strlen(t); i++)
        {
            if(t[i] == t[i+1])
            {
                flag = 1;
                for(j = i+2; j < strlen(t); j++)
                {
                    if(t[j] != t[i]) break;
                }
                n+= j-i;
                int m = i;
                for(int k = j; k < strlen(t); k++, m++)
                {
                    t[m] = t[k];
                }
                t[m] = 0;
                i--;
            }
        }
    }
//    printf("xiaochu: %s : %d n=%d\n", t, (int)strlen(t), n);
    return n;
}

void add(char * t, char * s, int p, char l)
{
    int i;
    for(i = 0; i < p ;i++)  t[i] = s[i];
    t[p] = l;

    for(i = p+1; i <= strlen(s); i++) t[i] = s[i-1];
    t[i] = 0;
}

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        char s[109];
        cin>>s;
        int ans = xiaochu(s);
        for(int j = 0; j < strlen(s)+1; j++)
        {
            char t[109];   
            add(t, s, j, 'A');
            ans = max(xiaochu(t), ans);
            add(t, s, j, 'B');
            ans = max(xiaochu(t), ans);
            add(t, s, j, 'C');
            ans = max(xiaochu(t), ans);
        }
        printf("%d\n", ans);
    }
 
    return 0;
}
