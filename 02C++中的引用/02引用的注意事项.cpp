//1.引用必须要初始化
//2.引用一旦初始化后，就不可以更改
#include <iostream>
using namespace std;
int main()
{
    int a=10;
    int &b=a;
    // int &c=b; 
    int c=20;
    // int &b;//错误，必须要初始化
    b=c;//赋值操作，而不是更改引用
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    cout<<"c="<<c<<endl;
    return 0;
}