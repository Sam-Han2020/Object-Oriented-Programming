#include <iostream>
using namespace std;
//两个派生类继承同一个基类
//又有某个类同时继承着两个派生类
//这种继承被称为菱形继承，或钻石继承

//动物类

class Animal
{
public:
    int m_Age;
};
//菱形继承带来的主要问题是子类继承两份相同的数据，导致资源浪费以及毫无意义
//利用虚继承可以解决菱形继承的问题
//继承之前加上关键字virtual变为虚继承
//Animal类成为虚基类
//羊类
class Sheep:virtual public Animal{};

//驼类
class Tuo:virtual public Animal{};

//羊驼类
class SheepTuo:public Sheep,public Tuo{};

void test01()
{
    SheepTuo st;
    st.Sheep::m_Age=18;
    st.Tuo::m_Age=28;
    //当菱形继承的时候，两个父类拥有相同的数据，需要加以作用域区分
    cout<<"st.Sheep::m_Age="<<st.Sheep::m_Age<<endl;
    cout<<"st.Tuo::m_Age="<<st.Tuo::m_Age<<endl;
    cout<<"sizeof(st)="<<sizeof(st)<<endl;
    cout<<"st.m_Age="<<st.m_Age<<endl;

    //这份数据我们知道只要有一份就可以了，菱形继承导致数据有两份，资源浪费
    //采用虚继承之后，m_Age就只有一份了
    //vbptr:虚基类指针 v-virtual b-base ptr-pointer vbtable  -- virtualbasetable(虚基类表，记录偏移地址)
}

int main()
{
    test01();
    return 0;
}