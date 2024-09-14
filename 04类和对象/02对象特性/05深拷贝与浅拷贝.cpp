#include <iostream>
using namespace std;

//深拷贝与浅拷贝，面试重点
//浅拷贝：简单的赋值拷贝操作
//深拷贝：在堆区重新开辟一块内存，进行拷贝操作

class Person
{
public:
    Person()
    {
        cout<<"Person的默认构造函数调用"<<endl;
    }
    Person(int age, int height)
    {
        m_Age=age;
        m_Height=new int(height);//利用new把数据创建在堆区
        cout<<"Person的有参构造函数调用"<<endl;
    }

    //自己实现拷贝构造函数，解决浅拷贝带来的问题
    Person(const Person &p)
    {
        cout<<"Person的拷贝构造函数调用"<<endl;
        m_Age=p.m_Age;
        m_Height=p.m_Height;//编译器默认实现就是这行代码
        // m_Height = new int(*p.m_Height);
    }

    ~Person()
    {
        //析构代码，将堆区开辟的数据做释放操作
        if(m_Height!=NULL) 
        {
            delete m_Height;
            m_Height=NULL;
        }
        cout<<"Person的析构函数调用"<<endl;
    }
    int m_Age;
    int *m_Height;
};

void test01()
{
    Person p1(18,180);
    cout<<"p1的年龄为："<<p1.m_Age<<" 身高为："<<*p1.m_Height<<endl;
    Person p2(p1);//如果利用编译器提供的拷贝构造函数，会做浅拷贝操作
    cout<<"p2的年龄为："<<p2.m_Age<<" 身高为："<<*p2.m_Height<<endl;
    //栈区数据先进后出，所以p2先被释放，p2被析构会释放一次堆区上的m_Height，之后p1析构会再释放一次，会出错。
    //浅拷贝带来的问题就是堆区的内存重复释放
    //浅拷贝的问题，要利用深拷贝进行解决
}

int main()
{
    test01();
    return 0;
}