#include <iostream>
using namespace std;

void showValue(const int &val)
{
    // val=1000;
    cout<<"val="<<val<<endl;
}

int main()
{
    //常量引用
    //使用场景：用来修饰形参，防止误操作

    int a=10;
    int &ref=a;//引用必须引一块合法的内存空间
    const int &r=10;//加上const之后，编译器将代码修改为int temp=10;const int &ref=temp;
    // r=20; //错误，加入const之后变成只读，不可以修改
    int b=100;
    showValue(b);
    cout<<"b="<<b<<endl;
    return 0;
}