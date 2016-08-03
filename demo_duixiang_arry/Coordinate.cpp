/*************************************************************************
        > File Name: coordinate.cpp
      > Author: dulun
      > Mail: dulun@xiyoulinux.org
      > Created Time: 2016年06月04日 星期六 17时54分10秒
 ************************************************************************/

#include<iostream>
#include "Coordinate.h"
using namespace std;

Coordinate::Coordinate(int x, int y)
{
    m_iX = x;
    m_iY = y;
    cout << "Coordinate " << m_iX << ", " <<  m_iY << endl;
}

Coordinate::~Coordinate()
{

    cout << "~Coordinate " << m_iX << ", " <<  m_iY << endl;
}

void Coordinate::setX(int x)
{
    m_iX = x;
}

void Coordinate::setY(int y)
{
    m_iY = y;
}

int Coordinate::getX()
{
    return m_iX;
}

int Coordinate::getY()
{
    return m_iY;
}

