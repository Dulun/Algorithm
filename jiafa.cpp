/*************************************************************************
	> File Name: jiafa.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月01日 星期二 22时32分15秒
 ************************************************************************/
#include<cstring>
#include<iostream>
#include<stdio.h>
using namespace std;

struct Big_add
{
    int d[600];
    int len;
    Big_add() {
        this->len = 0;
        memset(d, 0, sizeof(d));
    }
    Big_add(char s[])
    {
        memset(d, 0, sizeof(d));
        this->len = strlen(s);
        for(int i=0; i<this->len;i++)
        {
            d[this->len-i-1] = s[i] - '0';
        }
    }
    Big_add operator +(const Big_add &t)
    {
        Big_add ans = Big_add();
        for(int i=0; i<600; i++)
        {
            int c = t.d[i]+this->d[i];
            ans.d[i] += c%10;
            ans.d[i+1] += c/10;
        }
        int l = 599;
        while(l > 0 && ans.d[l] == 0)
            l--;
        ans.len = l;
        return ans;
    }
};
char a[600];
char b[600];
int main()
{
 cin>>a>>b;
    Big_add aa = Big_add(a);
    Big_add bb = Big_add(b);
    Big_add cc = aa + bb;
    for(int i=cc.len; i>=0; i--)
        cout<<cc.d[i];
}

