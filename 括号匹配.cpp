/*************************************************************************
        > File Name: 括号匹配.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月08日 星期五 01时21分05秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<stack>
#define LL long long
using namespace std;

const int N = 50086;
char a[N];
int main()
{

	int n;
	cin>>n;
	while(n--)
	{
		memset(a, 0, sizeof(a));
		cin>>a;
		stack<char> s;
		int len = strlen(a);
		bool flag = 0;
		for(int i = 0; i < len; i++)
		{
			if(a[i] == '(' || a[i] == '[' || a[i] == '{' )
			{
				s.push(a[i]);
			}
			else if(!s.empty())
			{
				char t = s.top();
				s.pop();
				if((a[i] == ')'  && t == '(')||( a[i] == ']' && t == '[') ||(t== '{' && a[i] == '}' ))
					continue;
				else
				{
					flag = 1;
					break;
				}
			}
			else
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0 && s.empty()) printf("Yes\n");
		else printf("No\n");
	}
    return 0;
}
