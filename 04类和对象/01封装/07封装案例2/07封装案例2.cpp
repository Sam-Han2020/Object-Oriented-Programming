#include <iostream>
using namespace std;
#include "point.h"
#include "circle.h"
// //点类
// class Point
// {
//     public:
//     void setX(int x){m_X=x;} 
//     int getX(){return m_X;}
//     void setY(int y){m_Y=y;}
//     int getY(){return m_Y;} 
//     private:
//     int m_X;
//     int m_Y;
// };
//圆类
// class Circle
// {
//     public:
//     void setR(int r) {m_R=r;}
//     int getR() {return m_R;}
//     void setCenter(Point c) {m_Center=c;}
//     Point getCenter() {return m_Center;}    
//     private:
//     int m_R;//半径
//     Point m_Center;//圆心
// };
//判断点和圆关系
void isInCircle(Circle &c,Point &p)
{
    int sd=(c.getCenter().getX()-p.getX())*(c.getCenter().getX()-p.getX())+(c.getCenter().getY()-p.getY())*(c.getCenter().getY()-p.getY());
    int sr=c.getR()*c.getR();
    if(sd==sr) cout<<"点在圆上"<<endl;
    else if(sd>sr) cout<<"点在圆外"<<endl;
    else cout<<"点在圆内"<<endl;
}
Point SetPoint(int x,int y)
{
    Point p;
    p.setX(x);
    p.setY(y);
    return p;
}
Circle SetCircle(const Point &c,int r)
{
    Circle o;
    o.setR(r);
    o.setCenter(c);
    return o;
}
int main()
{
    Point p=SetPoint(0,0);
    Circle c=SetCircle(SetPoint(10,0),11);
    isInCircle(c,p);
    return 0;
}