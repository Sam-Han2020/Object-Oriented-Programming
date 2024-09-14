#include <iostream>
using namespace std;

//赋值运算符的重载

class Person
{
public:
    Person(int age)
    {
        m_Age=new int(age);//堆区数据由程序员手动开辟与释放
    }
    ~Person()
    {
        if(m_Age!=NULL)
        {
            delete m_Age;
            m_Age=NULL;
        }
    }
    //重载赋值运算符
    Person& operator=(Person &p)
    {
        //编译器提供的是浅拷贝
        //m.Age=p.m_Age;

        //应当先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
        if(m_Age!=NULL)
        {
            delete m_Age;
            m_Age=NULL;
        }
        //深拷贝
        m_Age=new int(*p.m_Age);
        return *this;
    }
    int *m_Age;
};

void test01()
{
    Person p1(18);
    cout<<"p1的年龄为："<<*p1.m_Age<<endl;
    Person p2(20);
    cout<<"p2的年龄为："<<*p2.m_Age<<endl;
    p2=p1;//赋值运算操作
    cout<<"p1的年龄为："<<*p1.m_Age<<endl;
    cout<<"p2的年龄为："<<*p2.m_Age<<endl;
    Person p3(30);
    p3=p2=p1;
    cout<<"p1的年龄为："<<*p1.m_Age<<endl;
    cout<<"p2的年龄为："<<*p2.m_Age<<endl;
    cout<<"p3的年龄为："<<*p3.m_Age<<endl;
}

int main()
{
    test01();
    // int a=10,b=20,c=30;
    // c=b=a;
    // cout<<"a="<<a<<endl;
    // cout<<"b="<<b<<endl;
    // cout<<"c="<<c<<endl;
    return 0;
}
