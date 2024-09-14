#include <iostream>
using namespace std;
//引用做函数的返回值
//1.不要返回局部变量的引用
int& test01()
{
    int a=10;//存放在栈区
    return a;
}
//2.函数的调用可以作为左值存在
int& test02()
{
    static int a=10;//静态变量存放在全局区，全局区上的数据在程序结束后系统释放
    return a;
}
int main()
{
    // int &ref1=test01();
    // cout<<"ref1="<<ref1<<endl;//部分编译器第一次做了保留，无法输出，因为a的内存已经释放
    int &ref2=test02();
    cout<<"ref2="<<ref2<<endl;
    test02()=1000;//如果函数的返回值是引用，这个函数调用可以作为左值
    cout<<"ref2="<<ref2<<endl;
    return 0;
}