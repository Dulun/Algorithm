/*************************************************************************
        > File Name: hdu_1495.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月12日 星期二 11时58分33秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 286;
struct Node
{
	int a, b, c, n;
};
bool v[N][N][N];

void bfs(int a, int b, int c)
{//6种倒法
	queue<Node> q;
	memset(v, 0, sizeof(v));
	Node t, s;
	//t = (Node){a, 0, 0, 0};
	int end = a/2;
	t.a = a;
    t.b = 0;
    t.c = 0;
    t.n = 0;
	q.push(t);

	while(!q.empty())
	{
		Node t, s;
		t = q.front();
		q.pop();
		v[t.a][t.b][t.c] = true;
		if((t.a==end && t.b==end) || (t.b==end && t.c==end) || (t.a==end && t.c==end))
		{//达到目标,返回
			printf("%d\n", t.n);
			return ;
		}

		if(t.a != 0) //第一种倒法:将瓶子里的倒入第一个杯子
		{//可乐瓶非空
			if(t.a <= b-t.b)
			{//可以全部倒进第一个杯子
				s.a = 0;
				s.b = t.a + t.b;
				s.c = t.c;
				s.n = t.n+1;
			}

			else
			{//不能全部倒进第一个杯子
				s.a = t.a - (b-t.b);//倒满
			//	s.b = t.b + (b-t.b);
				s.b = b;            //第一个杯子被装满
				s.c = t.c;			//第二个杯子不变
				s.n = t.n+1;		//次数加一
			}
			if(!v[s.a][s.b][s.c])
			{//如果当前状态没有出现过,,入队
				v[s.a][s.b][s.c] = true;
				q.push(s);
			}

			//第二种倒发: 将瓶子里的倒入第二格杯子
			if(t.a <= c-t.c)
			{
				s.a = 0;
				s.b = t.b;
				s.c = t.c + t.a;
				s.n = t.n+1;
			}
			else
			{
				s.a = t.a - (c-t.c);
				s.b = t.b;
				s.c = c;
				s.n = t.n+1;
			}
			if(!v[s.a][s.b][s.c])
			{
				v[s.a][s.b][s.c] = true;
				q.push(s);
			}
		}

		if(t.b != 0) //第三种倒法:将第一个杯子里的,倒入瓶子里
		{
			if(t.b <= a-t.a)
			{
				s.a = t.a + t.b;
				s.b = 0;
				s.c = t.c;
				s.n = t.n+1;
			}
			else{
				s.a = a;
				s.b = t.b - (a-t.a);
				s.c = t.c;
				s.n = t.n+1;
			}
			if(!v[s.a][s.b][s.c])
			{
				v[s.a][s.b][s.c] = true;
				q.push(s);
			}
			//第四种倒发:
			if(t.b <= c-t.c)
			{
				s.c = t.b+t.c;
				s.a = t.a;
				s.n = t.n+1;
				s.b = 0;
			}
			else{
				s.c = c;
				s.a = t.a;
				s.n = t.n+1;
				s.b = t.b - (c-t.c);
			}

			if(!v[s.a][s.b][s.c])
			{
				v[s.a][s.b][s.c] = true;
				q.push(s);
			}
		}
		if(t.c != 0) //第5种
		{
			if(t.c <= (b-t.b))
			{
				s.c = 0;
				s.b = t.b+t.c;
				s.a = t.a;
				s.n = t.n+1;
			}
			else
			{
				s.c = t.c - (b-t.b);
				s.b = b;
				s.a = t.a;
				s.n = t.n+1;
			}
			if(!v[s.a][s.b][s.c])
			{
				v[s.a][s.b][s.c] = true;
				q.push(s);
			}
			//第六种:
			if(t.c <= (a-t.a))
			{
				s.c = 0;
				s.a = t.c+t.a;
				s.b = t.b;
				s.n = t.n+1;
			}
			else{
				s.c = t.c - (a-t.a);
				s.a = a;
				s.b = t.b;
				s.n = t.n+1;
			}
			if(!v[s.a][s.b][s.c])
			{
				v[s.a][s.b][s.c] = true;
				q.push(s);
			}
		}
	}
	printf("NO\n");
	return ;
}

int main()
{
	int a, b, c;
	while(scanf("%d%d%d", &a, &b, &c)!=EOF)
	{
	    if(a+b+c == 0) break;
		if(a & 1 == 1)
		{
			printf("NO\n");
			continue;
		}
		else{
		    bfs(a, b, c);
		}
	}

    return 0;
}
