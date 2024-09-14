#pragma once
#include <iostream>
using namespace std;
#include "point.h"
class Circle
{
    public:
    void setR(int r);
    int getR();
    void setCenter(Point c);
    Point getCenter(); 
    private:
    int m_R;//半径
    Point m_Center;//圆心
};