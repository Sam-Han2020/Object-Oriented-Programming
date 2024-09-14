#include <iostream>
using namespace std;

// 模板局限�?
// 模板并不是万能的，有些特定的数据类型，需要用具体化方式做特殊实现
// 利用具体化的模板，可以解决自定义类型的通用�?
// 学习模板并不是为了写模板，而是在STL能够运用系统提供的模�?
class Person
{
public:
    string name;
    int age;
    Person(string name, int age);
    ~Person();
    // 可以使用运算符重载，但是工作量大
    bool operator=(Person p)
    {
        return name == p.name && age == p.age;
    }
};

Person::Person(string name, int age)
{
    this->name = name;
    this->age = age;
}

Person::~Person()
{
}

// 对比两个数据是否相等的函�?
template <class T>
bool myCompare(T &a, T &b)
{
    if (a == b)
        return true;
    else
        return false;
}

// 利用具体化Person的版本实现代码，具体化优先调�?
template <>
bool myCompare(Person &a, Person &b)
{
    return a.name == b.name && a.age == b.age;
}

void test01()
{
    int a = 10;
    int b = 20;
    if (myCompare(a, b))
        cout << "a==b" << endl;
    else
        cout << "a!=b" << endl;
}

void test02()
{
    Person a("Tom", 10);
    Person b("Tom", 10);
    if (myCompare(a, b))
        cout << "a==b" << endl;
    else
        cout << "a!=b" << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}