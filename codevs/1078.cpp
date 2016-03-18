/*************************************************************************
	> File Name: 1078.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2015年12月02日 星期三 18时59分31秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int sum = 0;
    int low[100];
   // int adj[100];

    int min;
    int a[101][101];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cin>>a[i][j];
    }

   // adj[0] = low[0] = 0;
    for(int i = 1; i < n; i++)
    {
        low[i] = a[0][i];
       // adj[i] = 0;
    }

    int j = 1, k = 0;
    for(int i = 1; i < n; i++)
    {
        min = 99999999;
        j = 1; k = 0;
        while(j < n)
        {
            if(low[j] != 0 && low[j] < min)
            {
                min = low[j];
                k = j;
            }
            j++;
        }
       // sum += a[adj[k]][k];
        sum += low[k];
        low[k] = 0;//入树
        for(j = 1; j < n; j++)
        {                   //a[k][j]:与新加入树的点相连的点
            if(low[j] != 0 && a[k][j] < low[j])//if当前入树的点
            //能到达的，比以前能到达的顶点，更近，则更新；
            {
                low[j] = a[k][j];
               // adj[j] = k;  //与其相邻的点
                // adj[i] 与 i相连 的最小距离为 low[i]  == a[adj[i]][i] 或 ==a[i][adj[i]];
            }
        }
    }

    cout<<sum;

}
