#include <iostream>
using namespace std;

//拷贝构造函数调用时机

class Person
{
    public:
    Person()
    {
        cout<<"Person默认构造函数调用"<<endl;
    }
    Person(int age)
    {
        m_Age=age;
        cout<<"Person有参构造函数调用"<<endl;
    }
    Person(const Person &p)
    {
        m_Age=p.m_Age;
        cout<<"Person拷贝构造函数调用"<<endl;
    }
    ~Person()
    {
        cout<<"Person析构函数调用"<<endl;
    }
    int m_Age;
};

//1.使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
    Person p1(20);
    Person p2(p1);
    cout<<"P2的年龄为："<<p2.m_Age<<endl;
}
//2.值传递的方式给函数参数传值

void doWork(Person p)
{
    p.m_Age=10;
}
void test02()
{
    Person p(20);
    doWork(p);
    cout<<"P的年龄为："<<p.m_Age<<endl;
}
//3.值方式返回局部对象
//哦，我大概明白了，首先p是外面的，不用担心被释放的问题，
//p的地址传进去，里面通过一系列赋值对这个p（就是里面的p1）进行修饰，也达到了目的。
//本来是p1出来，现在是p进去
Person doWork2()
{
    Person p1;
    cout<<(int*)&p1<<endl;
    return p1;
}
void test03()
{
    Person p=doWork2();
    cout<<(int*)&p<<endl;
}
int main()
{
    test03();
    return 0;
}