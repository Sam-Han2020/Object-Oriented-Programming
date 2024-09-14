#pragma once
#include <iostream>
using namespace std;
//点类
class Point
{
    public:
    void setX(int x);
    int getX();
    void setY(int y);
    int getY();
    private:
    int m_X;
    int m_Y;
};