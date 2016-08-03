/*************************************************************************
        > File Name: Line.h
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年06月04日 星期六 19时34分28秒
 ************************************************************************/

#ifndef _LINE_H
#define _LINE_H
#include "Coordinate.h"

class Line
{
public:
    Line(int x1, int y1, int x2, int y2);
    ~Line();
    void setA(int x, int y);
    void setB(int x, int y);
    void printInfo();

private:
    Coordinate m_coorA;
    Coordinate m_coorB;
};
#endif
