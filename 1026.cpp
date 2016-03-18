/*************************************************************************
	> File Name: 1026.cpp
	> Author: dulun
	> Mail: dulun@xiyoulinux.org
	> Created Time: 2016年03月10日 星期四 21时33分31秒
 ************************************************************************/

#include<stdio.h>
#include<iostream>
using namespace std;
const int MAX_N = 51;
const int MAX_M = 1001;
int R, C, N;
int x, y;
int turn[MAX_M];             //移动方向 ，turn[t] 表示 第t个方向 
int M[MAX_N][MAX_N];         //以0，1存储原地图，方便判断 
char A[MAX_N][MAX_N];        //以字符存储行驶后的地图，方便输出 
int vis[MAX_N][MAX_N][MAX_M];    //vis[x][y][t] 表示 从点（x,y）往第t个方向（turn[t]）移动 
void DFS(int x, int y, int t)
{
	if (vis[x][y][t]) return;     //如果该移动状态出现过了，则不考虑 
	vis[x][y][t] = 1;             //没出现过，则考虑，标记。。 
	if (t > N)      //如果遍历完所有行驶方向，则得到一个目标可能点。
	{
		A[x][y] = '*';
		return;
	}
	if (turn[t] == 1)            //北（上）
	{
		x--;                    //向上移动一步 
		while (x >= 1 && M[x][y])  //约束条件，一直行驶直到无法继续 
		{
			DFS(x, y, t + 1);   //从当前点开始搜索，按照turn的顺序行驶，每个方向都要走到边界 
			x--;
		}
	}
	if (turn[t] == 2)            //南（下）
	{
		x++;
		while (x <= R && M[x][y])
		{
			DFS(x, y, t+1);
			x++;
		}
	}
	if (turn[t] == 3)                //西（左） 
	{
		y--;
		while (y >= 1 && M[x][y])
 		{
			DFS(x, y, t + 1);
			y--; 
		} 
	}                
	if (turn[t] == 4)              //东（右）
	{
		y++;
		while (y <= C && M[x][y])
		{
			DFS(x, y, t + 1);
			y++;
		}
	}
}
int main()
{
	int i, j;
	cin>>R>>C;
	for (i = 1; i <= R; i++)
	{
		for (j = 1; j <= C; j++)
		{
			cin>>A[i][j];
			if (A[i][j] == '.')	M[i][j] = 1;
			if (A[i][j] == 'X')	M[i][j] = 0;
			if (A[i][j] == '*') 
			{
				A[i][j] = '.';
				M[i][j] = 1;
				x = i;
				y = j;
			}
		}
	}
	cin>>N;
	for (i = 1; i <= N; i++)
	{
		char dir[5];
		cin>>dir;
		if (dir[0] == 'N') turn[i] = 1;              
		if (dir[0] == 'S') turn[i] = 2;
		if (dir[0] == 'W') turn[i] = 3;
		if (dir[0] == 'E') turn[i] = 4;
	}
	DFS(x, y, 1);
	for (i = 1; i <= R; i++)
	{
		for (j = 1; j <= C; j++)
			printf("%c", A[i][j]);
		if(i != R) 
			printf("\n");
	}
	return 0;
}
