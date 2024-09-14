#include <iostream>
using namespace std;

template <class T1, class T2>
class Person
{
public:
    T1 m_Name;
    T2 m_Age;
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

// 1.指定传入类型

void printPerson1(Person<string, int> &p)
{
    p.showPerson();
}

void test01()
{
    Person<string, int> p("sunwukong", 100);
    printPerson1(p);
}

// 2.参数模板化
template <class T1, class T2>
void printPerson2(Person<T1, T2> &p)
{
    p.showPerson();
}

void test02()
{
    Person<string, int> p("zhubajie", 90);
    printPerson2(p);
}

// 3.整个类模板化
template <class T>
void printPerson3(T &p)
{
    p.showPerson();
}

void test03()
{
    Person<string, int> p("tangseng", 30);
    printPerson3(p);
}

int main()
{
    // test01();
    test03();
    return 0;
}