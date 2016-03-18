/*************************************************************************
	> File Name: 1459.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2015年12月07日 星期一 10时22分24秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;
const int inf = 19999999;
int arc[600][600];
int n, m, s, e;
int score[600] = {0};
int allscore[600] ;
bool visited[600] = {0};
int d[600];

int dij()
{
    allscore[s] = score[s];

    for(int i = 0; i < n; i++)
    {
        d[i] = arc[s][i];
        if(arc[s][i] != inf)
            allscore[i] = allscore[s] + score[i];
    }


    d[s] = 0;
    visited[s] = 1;
    int k;
    for(int o = 1; o < n; o++)
    {
        int min = inf;
        for(int i = 0; i < n; i++)
        {
            if( !visited[i] && d[i] > 0 && d[i] < min)
            {
                k = i;
                min = d[i];
            }
        }
        
        visited[k] = 1;
        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && d[i]  > arc[k][i] + min  && d[i] != 0)
            {
                d[i] = min + arc[k][i];
                allscore[i] = allscore[k] + score[i];
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && d[i] == arc[k][i] + d[k])
            {
                if(allscore[i] < allscore[k] + score[i])
                    allscore[i] = allscore[k] + score[i];
            }
        }
        if(k == e) break;
    }
    printf("%d %d", d[e], allscore[e]);
    return 0; 
}

int main()
{
//    cin>>n>>m>>s>>e;
    scanf("%d%d%d%d", &n, &m, &s, &e);
//    n = 3, m = 2 ,s = 0, e = 2;
    int x, y, w;
 
    for(int i = 0; i < n; i++) scanf("%d", &score[i]);
//    score[0] = 1, score[1] = 2 , score[2] = 3;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) arc[i][j] = inf;
    

//    arc[0][1] = arc[0][1] = 10;
  //  arc[1][2] = arc[2][1] = 11;
   for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &x, &y, &w);
        arc[x][y] = w;
        arc[y][x] = w;
    }
    
    dij();
    
}
