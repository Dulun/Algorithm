/*************************************************************************
        > File Name: poj_3414.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月13日 星期三 12时59分54秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 186;
struct Node
{
	int a, b, step;
	char str[N][N];
};

bool v[N][N];

void bfs(int a, int b, int c)
{
	memset(v, 0, sizeof(v));
	Node t, s;
	queue<Node> q;
	t = (Node){0, 0, 0};
	q.push(t);
	v[t.a][t.b] = true;

	while(!q.empty())
	{
		t = q.front();
		q.pop();
		v[t.a][t.b] = true;
		if(t.a == c || t.b == c)
		{
			printf("%d\n", t.step);
			for(int i = 1; i <= t.step; i++)
			{
				printf("%s\n", t.str[i]);
			}
			return ;
		}

		if(t.a == 0)
		{
			s = t;
			s.a = a;
			s.step++;
			strcpy(s.str[s.step], "FILL(1)");
			if(!v[s.a][s.b])
			{
				v[s.a][s.b] = true;
				q.push(s);
			}
		}
		else if(t.a <= a)
		{
			s = t;
			s.a = 0;
			s.step++;
			strcpy(s.str[s.step], "DROP(1)");
			if(!v[s.a][s.b])
			{
				v[s.a][s.b] = true;
				q.push(s);
			}
			if(t.b < b)
			{
				s = t;
				if(t.a+t.b <= b)
				{
					s.a = 0;
					s.b = t.a+t.b;
				}
				else{
					s.a = t.a - (b-t.b);
					s.b = b;
				}
				s.step++;
				strcpy(s.str[s.step], "POUR(1,2)");
				if(!v[s.a][s.b])
				{
					v[s.a][s.b] = true;
					q.push(s);
				}
			}
		}

		if(t.b == 0)
		{
			s = t;
			s.b = b;
			s.step++;
			strcpy(s.str[s.step], "FILL(2)");
			if(!v[s.a][s.b])
			{
				v[s.a][s.b] = true;
				q.push(s);
			}
		}
		else if(t.b <= b)
		{
			s = t;
			s.b = 0;
			s.step++;
			strcpy(s.str[s.step], "DROP(2)");
			if(!v[s.a][s.b])
			{
				v[s.a][s.b] = true;
				q.push(s);
			}
			if(t.a < a)
			{
				if(t.a+t.b < a)
				{
					s = t;
					s.a = t.a+t.b;
					s.b = 0;
				}
				else{
					s = t;
					s.a = a;
					s.b = t.b - (a-t.a);
				}
				s.step++;
				strcpy(s.str[s.step], "POUR(2,1)");
				if(!v[s.a][s.b])
				{
					v[s.a][s.b] = true;
					q.push(s);
				}
			}
		}

	}
	printf("impossible\n");
	return;

}

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	bfs(a, b, c);
    return 0;
}
