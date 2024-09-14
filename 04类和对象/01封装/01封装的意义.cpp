#include <iostream>
using namespace std;
#define PI 3.1415926
//设计一个圆类，求圆的周长
//圆求周长的公式：2*PI*半径

//class代表设计一个类，类后面紧跟着的就是类名称

class Circle
{
    //访问权限
    //公共权限
    public:
    //属性
    //半径
    int m_r;
    //行为
    //获取圆的周长
    double calculateZC()
    {
        return 2*PI*m_r;
    }
};

//学生类
class Student
{
    public:
    string name;
    string id;
    void setName(string n)
    {
        name=n;
    }
    void setID(string i)
    {
        id=i;
    }
    void PrintStu()
    {
        cout<<"姓名："<<name<<'\t'<<"学号："<<id<<endl;
    }
};

int main()
{
    //通过圆类，创建具体的圆（对象）
    //实例化（通过一个类，创建一个对象的过程）
    Circle c1;
    //给圆对象的属性进行赋值
    c1.m_r=10;
    cout<<"圆的周长为："<<c1.calculateZC()<<endl;
    return 0;
}