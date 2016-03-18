/*************************************************************************
	> File Name: 1426.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年01月25日 星期一 11时47分33秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

struct queue{
    long long x;
};

queue q[20000000];

void bfs(int n)
{
    int front, rear;
    q[front = rear = 0].x = 1;
    rear++;

    while(front < rear)
    {
        if(q[front].x % n != 0)
        {
            q[rear++].x = q[front].x * 10;
            q[rear++].x = q[front].x * 10 + 1;
        }
        else
        {
            printf("%lld\n", q[front].x);
            return;
        }
        front+=1;
    }
}


int main()
{
    while(1)
    {
        int n;
        scanf("%d", &n);
        if(0 == n) break;
        bfs(n);
    }
    return 0;
}
