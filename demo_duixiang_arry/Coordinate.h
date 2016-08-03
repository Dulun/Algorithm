/*************************************************************************
        > File Name: coordinate.h
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年06月04日 星期六 17时53分43秒
 ************************************************************************/

#ifndef _COORDINATE_H
#define _COORDINATE_H

class Coordinate
{
public:
    Coordinate(int x, int y);
    ~Coordinate();
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
private:
    int m_iX;
    int m_iY;
};

#endif
