#include <iostream>
using namespace std;

// 普通函数与函数模板的调用规�?
// 1.如果函数模板和普通函数都可以调用，优先调用普通函�?
// 2.可以通过空模板参数列表，强制调用函数模板
// 3.函数模板也可以发生函数重�?
// 4.如果函数模板可以产生更好的匹配，优先调用函数模板

// 实际开发，提供函数模板，不要提供普通函数，避免出现二义�?

void myPrint(int a, int b)
{
    cout << "putong" << endl;
}

template <class T>
void myPrint(T a, T b)
{
    cout << "muban" << endl;
}

template <class T>
void myPrint(T a, T b, T c)
{
    cout << "muban2" << endl;
}

void test01()
{
    int a = 10;
    int b = 10;
    // 1.如果函数模板和普通函数都可以调用，优先调用普通函�?
    // 即使只留下普通函数的声明，也不会调用模板
    myPrint(a, b);
    // 2.可以通过空模板参数列表，强制调用函数模板
    myPrint<>(a, b);
    // 3.函数模板也可以发生函数重�?
    myPrint(a, b, 100);
    // 4.如果函数模板可以产生更好的匹配，优先调用函数模板
    char c1 = 'A', c2 = 'B';
    myPrint(c1, c2);
}

int main()
{
    test01();
    return 0;
}