/*************************************************************************
	> File Name: 2251.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年01月20日 星期三 12时32分28秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
using namespace std;

struct q
{
    int x, y, z;
    int length;
}q[30000]; //模拟队列

int xx[] = {1, -1, 0, 0, 0, 0};
int yy[] = {0, 0, 0, 0, -1, 1};
int zz[] = {0, 0, -1, 1, 0, 0};

bool visit[40][40][40];
char map  [40][40][40];
int l, r, c, sx, sy, sz;

int bfs()
{
    int cur, pre, dx, dy, dz;
    memset(visit, false, sizeof(visit));

    q[0].x = sx, q[0].y = sy, q[0].z = sz;
    pre = cur = 0;
    
    while(pre <= cur)
    {
        for(int i = 0; i < 6; i++)
        {//6个方向
            dx = q[pre].x + xx[i];
            dy = q[pre].y + yy[i];
            dz = q[pre].z + zz[i];            
            
            if(!visit[dx][dy][dz] &&                          //未访问 
            (map[dx][dy][dz]=='.' || map[dx][dy][dz]=='E') && //能走
             dx>=0 && dx<l && dy>=0 && dy<r && dz>=0 && dz<c) //没越界
            {//如果能走，则入队
                visit[dx][dy][dz] = true;//访问
                cur += 1;                
                q[cur].x = dx;
                q[cur].y = dy;
                q[cur].z = dz;
                q[cur].length = q[pre].length + 1;
                if(map[dx][dy][dz] == 'E') return q[cur].length;
            }
        }
        pre += 1;//出队
    }
    return 0;
}


int main()
{
    int i, j, k, ans;
//  while(scanf("%d%d%d", &l, &r, &c))
    while(scanf("%d%d%d\n", &l, &r, &c)) //这/n把我坑惨了！！
    {
        if(l == 0 && r == 0 && c == 0) break;
        for(i = 0; i < l; i++,getchar())
        for(j = 0; j < r; j++,getchar())
        for(k = 0; k < c; k++)
        {
            scanf("%c", &map[i][j][k]);
            if(map[i][j][k] == 'S') sx = i, sy = j, sz = k;
        }
        
        ans = bfs();
        if(ans) printf("Escaped in %d minute(s).\n", ans);//这里有一个"."
        else    printf("Trapped!\n");
    }
    return 0;
}

