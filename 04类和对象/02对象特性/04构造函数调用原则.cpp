#include <iostream>
using namespace std;

//构造函数的调用规则
//1.创建一个类，C++编译器会给每个类都添加至少3个函数
//默认构造（空实现）
//析构函数（空实现）
//拷贝构造（值拷贝）

//2.如果我们写了有参构造函数，编译器就不再提供默认构造函数，但提供拷贝构造函数
//如果我们写了拷贝构造函数，编译器就不提供其他普通构造函数了！！！
class Person
{
private:
    /* data */
public:
    Person()
    {
        cout<<"Person的默认构造函数调用"<<endl;
    }
    Person(int age)
    {
        m_Age=age;
        cout<<"Person的有参构造函数调用"<<endl;
    }
    // Person(const Person &p)
    // {
    //     m_Age=p.m_Age;
    //     cout<<"Person的拷贝构造函数调用"<<endl;
    // }//如果不写，系统自动会提供
    ~Person()
    {
        cout<<"Person的析构函数调用"<<endl;
    }

    int m_Age;
};

// void test01()
// {
//     Person p;
//     p.m_Age=18;
//     Person p2(p);
//     cout<<"p2的年龄为："<<p2.m_Age<<endl;
// }

void test02()
{
    Person p(18);
    Person p2(p);
    cout<<"p2的年龄为："<<p2.m_Age<<endl;
}
int main()
{
    // test01();
    test02();
    return 0;
}