/*************************************************************************
	> File Name: 1212_kruskal.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2015年12月03日 星期四 20时10分49秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

struct Edge{
    int begin;
    int end;
    int weight;
};

Edge e[50009];
int parent[10000];

bool cmp(Edge a, Edge b)
{
    return a.weight < b.weight;
}

int find(int f)
{
    if(parent[f] == f) return f;
    return parent[f] = find(parent[f]);
}

int main()
{
    int m, n;
    scanf("%d%d", &n, &m);
    
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &e[i].begin, &e[i].end, &e[i].weight);
    }
    for(int i = 0; i < n+1; i++) parent[i] = i;
    sort(e, e + m, cmp);

    int sum = 0;
    int count = 0;
    for(int i = 0; i < m; i++)
    {
        if(count >= n-1) break;
        int p = find(e[i].begin);
        int q = find(e[i].end);
        if(p != q)
        {
            if(p < q)
            {
                parent[p] = q;
            }
            else
                parent[q] = p;
            count ++;
            sum += e[i].weight;
        }
    }

    printf("%d\n", sum);

}
