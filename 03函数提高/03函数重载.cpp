#include <iostream>
using namespace std;

//函数重载
//可以让函数名相同，提高复用性

//函数重载的满足条件
//1.同一个作用域下
//2.函数的名称相同
//3.函数参数类型不同，或者个数不同，或者顺序不同
// void func()
// {
//     cout<<"func的调用"<<endl;
// }
// void func(int a)
// {
//     cout<<"func(int a)的调用"<<endl;
// }
// void func(double a)
// {
//     cout<<"func(double a)的调用"<<endl;
// }
// void func(int a,double b)
// {
//     cout<<"func(int a,double b)的调用"<<endl;
// }
// void func(double a,int b)
// {
//     cout<<"func(double a,int b)的调用"<<endl;
// }
//注意事项
//1.函数的返回值不可以作为函数重载的条件
// int func(double a,int b)//错误的
// {
//     cout<<"func(double a,int b)的调用"<<endl;
// }

//2.引用作为重载的条件
void func(int &a)//int &a=10是不合法的
{
    cout<<"func(int &a)调用"<<endl;
}
void func(const int &a)//const int &a=10是合法的
{
    cout<<"func(const int &a)调用"<<endl;
}
//3.函数重载碰到默认参数
void func2(int a)
{
    cout<<"func2(int a)的调用"<<endl;;
}
void func2(int a,int b=10)
{
    cout<<"func2(int a,int b=10)的调用"<<endl;;
} //主程序func2(10);会导致报错
int main()
{
    // int a=10;
    // func(a);
    func2(10,20);//当函数重载碰到默认参数，出现二义性，报错，尽量避免这种情况
    return 0;
}