#include <iostream>
using namespace std;

// 类模板与函数模板的区�?
template <class NameType, class AgeType = int>
class Person
{
public:
    NameType m_Name;
    AgeType m_Age;
    Person(NameType name, AgeType age)
    {
        m_Name = name;
        m_Age = age;
    }
    void showPerson()
    {
        cout << "name: " << m_Name << " age: " << m_Age << endl;
    }
};

// 1.类模板没有自动类型推导的使用方式
void test01()
{
    // Person p("sunwukong", 1000); //错误�?
    Person<string, int> p("sunwukong", 1000);
    p.showPerson();
}
// 2.类模板在模板参数列表中可以有默认参数
void test02()
{
    Person<string> q("zhubajie", 999);
    q.showPerson();
}

int main()
{
    test01();
    test02();
    return 0;
}