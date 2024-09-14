#include <iostream>
using namespace std;

//初始化列表
class Person
{
public:
    
    // //传统初始化操作，创建对象赋初值
    // Person(int a,int b,int c)
    // {
    //     m_A=a;
    //     m_B=b;
    //     m_C=c;
    // }

    //初始化列表初始化属性
    Person(int a,int b,int c):m_A(a),m_B(b),m_C(c){/*括号里面可以不写*/}

    int m_A;
    int m_B;
    int m_C;
};

void test01()
{
    Person p(30,20,10);
    // Person p;
    cout<<"m_A="<<p.m_A<<" m_B="<<p.m_B<<" m_C="<<p.m_C<<endl;
}

int main()
{
    test01();
    return 0;
}