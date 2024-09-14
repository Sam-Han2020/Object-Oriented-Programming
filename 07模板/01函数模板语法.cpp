#include <iostream>
using namespace std;

// 函数模板

// 交换两个整型函数
void swapInt(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

// 交换两个浮点型函数
void swapDouble(double &a, double &b)
{
    double t = a;
    a = b;
    b = t;
}

// 函数模板
template <typename T> // 声明一个模板，告诉编译器后面代码中的T不要报错，T是一个通用数据类型
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test01()
{
    int a = 10;
    int b = 20;
    swapInt(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

void test02()
{
    int a = 10;
    int b = 20;
    // 两种方式使用模板
    // 1.自动类型推导
    // mySwap(a, b);
    // 2.显示指定类型
    mySwap<int>(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

int main()
{
    test02();
    system("pause");
    return 0;
}