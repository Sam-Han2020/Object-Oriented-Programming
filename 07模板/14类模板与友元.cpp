#include <iostream>
using namespace std;

// 通过全局函数来打印Person的信息

template <class T1, class T2>
class Person;

// 2.全局函数类外实现
template <class T1, class T2>
void printPerson2(Person<T1, T2> p)
{
    cout << "leiwaishixian name: " << p.m_Name << " age: " << p.m_Age << endl;
}

template <class T1, class T2>
class Person
{
    // 1.全局函数类内实现
    friend void printPerson(Person<T1, T2> p)
    {
        cout << "name: " << p.m_Name << " age: " << p.m_Age << endl;
    }
    // 2.全局函数类外实现
    // 加空模板参数列表
    // 如果全局函数是类外实现的话，需要让编译器提前知道这个函数的存在
    friend void printPerson2<>(Person<T1, T2> p);

private:
    T1 m_Name;
    T2 m_Age;

public:
    Person(T1 name, T2 age)
    {
        m_Name = name;
        m_Age = age;
    }
    void showPerson()
    {
        cout << "name: " << m_Name << " age: " << m_Age << endl;
    }
};

// 1.全局函数类内实现
void test01()
{
    Person<string, int> p("Tom", 20);
    printPerson(p);
}

void test02()
{
    Person<string, int> p("Tom", 20);
    printPerson2(p);
}

int main()
{
    // test01();
    test02();
    return 0;
}