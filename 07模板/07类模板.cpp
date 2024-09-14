#include <iostream>
using namespace std;

// 类模�?
template <class NameType, class AgeType>
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

void test01()
{
    Person<string, int> p1("sunwukong", 999);
    p1.showPerson();
}

int main()
{
    test01();
    return 0;
}