/*************************************************************************
        > File Name: i.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年04月21日 星期四 13时57分09秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
const int N = 1009;
int w[N], v[N];
struct Node
{
	int w, v;
};
int n, W;

vector<Node> dfs(int l, int r)
{
	int mid = (l+r)/2;
	Node t = {0, 0};
	vector<Node> c;
	c.push_back(t);
	if(l == r)
	{
		t.w = w[l];
		t.v = v[l];
		c.push_back(t);
		return c;
	}
	if(l > r)
		return c;

	vector<Node> a = dfs(l, mid);
	vector<Node> b = dfs(mid+1, r);
	for(int i=0; i<a.size(); i++)
		for(int j=0; j<b.size(); j++)
		{
			t.w = a[i].w + b[i].w;
			t.v = a[i].v + b[i].v;
			if(t.w <= W)
				c.push_back(t);
		}
	return c;
}

int main()
{
	while(cin>>n>>W)
	{
		for(int i = 0; i < n; i++)
			scanf("%d%d", &w[i], &v[i]);
		vector<Node> ans = dfs(0, n-1);
		int rel = 0;
		for(int i=0; i<ans.size(); i++)
			rel = max(rel, ans[i].v);
		printf("%d\n", rel);
	}
}
