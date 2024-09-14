#include <iostream>
using namespace std;

//建筑物类
class Building
{
    //goodGay全局函数是Building好朋友，可以访问Building的private成员
    friend void goodGay(Building &buliding);
public:
    Building()
    {
        m_SittingRoom="客厅";
        m_BedRoom="卧室";
    }
    string m_SittingRoom;//客厅
private:
    string m_BedRoom;//卧室    
};

//全局函数
void goodGay(Building &buliding)
{
    cout<<"好基友的全局函数正在访问："<<buliding.m_SittingRoom<<endl;
    cout<<"好基友的全局函数正在访问："<<buliding.m_BedRoom<<endl;//错误的
}
void test01()
{
    Building buliding;
    goodGay(buliding);
}
int main()
{
    test01();
    return 0;
}