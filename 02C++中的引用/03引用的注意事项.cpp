#include <iostream>
using namespace std;
//交换函数

//1.值传递
void mySwap01(int a,int b)
{
    int t=a;
    a=b;
    b=t;
    // cout<<"swap01 a="<<a<<endl;
    // cout<<"swap01 b="<<b<<endl;
}
//2.地址传递
void mySwap02(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
//3.引用传递
void mySwap03(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}
void PrintNum(int a,int b)
{
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
}
int main()
{
    int a=10;
    int b=20;
    mySwap01(a,b);//值传递，形参不会修饰实参
    PrintNum(a,b);
    mySwap02(&a,&b);//地址传递，形参会修饰实参
    PrintNum(a,b);
    mySwap03(a,b);
    PrintNum(a,b);
}