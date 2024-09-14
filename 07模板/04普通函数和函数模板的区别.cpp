#include <iostream>
using namespace std;

/*
1.普通函数调用可以发生隐式类型转�?
2.函数模板 用自动类型推�? 不可以发生隐式类型转�?
3.函数模板 用显式指定类�? 可以发生隐式类型转换
*/

// 普通函�?

int myAdd01(int a, int b)
{
    return a + b;
}

// 函数模板

template <class T>
T myAdd02(T a, T b)
{
    return a + b;
}

// 1.普通函数调用可以发生隐式类型转�?
void test01()
{
    int a = 10;
    char b = 'c'; // ascii('c')=99
    cout << myAdd01(a, b) << endl;
}

// 2.函数模板 用自动类型推�? 不可以发生隐式类型转�?
void test02()
{
    int a = 10;
    char b = 'c'; // ascii('c')=99
    // cout << myAdd02(a, b) << endl;//错误�?
}

// 3.函数模板 用显式指定类�? 可以发生隐式类型转换
void test03()
{
    int a = 10;
    char b = 'c'; // ascii('c')=99
    cout << myAdd02<int>(a, b) << endl;
}

int main()
{
    test03();
    return 0;
}