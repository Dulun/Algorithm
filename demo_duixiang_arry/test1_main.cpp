/*************************************************************************
        > File Name: man.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年06月04日 星期六 17时53分29秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include "Coordinate.cpp" 
using namespace std;
const int N = 50086;
 
int main()
{
    Coordinate coor[3];
    coor[0].m_iX = 3;
    coor[0].m_iY = 5;

    Coordinate *p = new Coordinate[3];
    p->m_iX = 7;
    p[0].m_iY = 9;

    p++;
    p->m_iX = 11;
    p[0].m_iY = 13;

    p[1].m_iX = 15;
    p++;
    p->m_iY = 17;

    for(int i = 0; i < 3; i++)
    {
        cout << "Coor_x = " << coor[i].m_iX << endl;
        cout << "Coor_y = " << coor[i].m_iY << endl;

    }

    for(int i = 0; i < 3; i++)
    {
        cout << "p_x = " << p[i-2].m_iX << endl;
        cout << "p_y = " << p[i-2].m_iY << endl;
    }
    printf("\n");

    for(int i = 0; i < 3; i++)
    {//倒序
        cout << "p_x = " << p->m_iX << endl;
        cout << "p_y = " << p->m_iY << endl;
        p--;
    }
    
    p++;
    //delete p; //  不加中括号，只销毁第一个元素, 内存泄漏
    delete[] p;
    p = NULL;

    Coordinate * q = new Coordinate;
    printf("\nhello\n");
    delete q;
    printf("world\n");
    
    int *w = new int[100];
    delete[] w;

    return 0;
}
