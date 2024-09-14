#include <iostream>
using namespace std;

//常函数 
class Person
{
public:
    //this指针的本质，是指针常量，指针的指向是不可以修改的
    //(const) Person * const this
    //在成员函数后面加const，修饰的是this指针，让指针指向的值也不可以修改
    Person() {}
    void func() {}
    void showPerson() const//(const)
    {
        this->m_B=100;//加上const就是错误的
        // this=NULL; //错误的，this指针不可以修改指针的指向的
    }
    int m_A;
    mutable int m_B;//特殊变量，即使在常函数中，也可以修改这个值(mutable)
};

void test01()
{
    Person p;
    p.showPerson();
}

//常对象

void test02()
{
    const Person p;//在对象前加const,变为常对象
    // p.m_A=100;//错误的，在常对象下不可修改
    p.m_B=100;//m_B是特殊值，在常对象下也可以修改
    // cout<<p.m_B<<endl;
    //常对象只能调用常函数
    p.showPerson();
    //p.func();//错误的，常对象只能调用常函数，不可以调用普通成员函数，以保证成员对象属性不被修改
}

int main()
{
    test02();
    return 0;
}