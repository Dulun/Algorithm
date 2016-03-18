/*************************************************************************
	> File Name: 1142.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年02月29日 星期一 13时29分23秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>

using namespace std;

struct stu
{
    int a, b, c, sum;
    int num;
};

stu st[1008];
bool cmp(stu p, stu q)
{
    if(p.sum != q.sum) return p.sum > q.sum;
    if(p.a != q.a) return p.a > q.a;
    return p.num < q.num;
}

int main()
{

    int m, n;
    cin>>m;

    for(int i = 0; i < m; i++)
    {
        cin>> st[i].a >> st[i].b >> st[i].c;
        st[i].sum = st[i].a + st[i].b + st[i].c;
        st[i].num = i;
    }

    sort(st, st + m, cmp);

    for(int i = 0; i < 5; i++)
    {
        cout<<st[i].num+1<<" "<<st[i].sum<<endl;
    }
    return 0;
}
