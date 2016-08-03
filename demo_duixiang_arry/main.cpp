/*************************************************************************
        > File Name: main.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年06月04日 星期六 19时54分01秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#define LL long long
using namespace std;

#include "Line.cpp"
#include "Coordinate.cpp"
//#include "Line.h"

const int N = 50086;
 
int main()
{
    Line *p = new Line(1, 2, 3, 4);
    p->printInfo();
    delete p;
 
    return 0;
}
