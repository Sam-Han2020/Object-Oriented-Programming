#include <iostream>
using namespace std;
#include "MyArray.hpp"

// 测试自定义的数据类型
class Person
{
public:
    string m_Name;
    int m_Age;
    Person() {}
    Person(string name, int age)
    {
        m_Age = age;
        m_Name = name;
    }
};

void printIntArray(MyArray<int> &arr)
{
    for (int i = 0; i < arr.getSize(); ++i)
    {
        cout << arr[i] << endl;
    }
}

void printPersonArray(MyArray<Person> &arr)
{
    for (int i = 0; i < arr.getSize(); ++i)
    {
        cout << "name:" << arr[i].m_Name << " age:" << arr[i].m_Age << endl;
    }
}

void test01()
{
    MyArray<int> arr1(5);
    for (int i = 0; i < 5; ++i)
    {
        // 利用尾插法向数组中插入数据
        arr1.Push_Back(i);
    }
    cout << "arr1:" << endl;
    printIntArray(arr1);

    MyArray<int> arr2(arr1);
    arr2.Pop_Back();
    cout << "arr2:" << endl;
    printIntArray(arr2);
    // MyArray<int> arr3(100);
    // arr3 = arr1;
}

void test02()
{
    MyArray<Person> arr(10);
    Person p1("sunwukong", 999);
    Person p2("hanxing", 30);
    Person p3("daji", 20);
    Person p4("zhaoyun", 25);
    Person p5("anqila", 27);

    // 将数据插入到数组中
    arr.Push_Back(p1);
    arr.Push_Back(p2);
    arr.Push_Back(p3);
    arr.Push_Back(p4);
    arr.Push_Back(p5);

    // 打印数组
    printPersonArray(arr);
}

int main()
{
    test02();
    return 0;
}