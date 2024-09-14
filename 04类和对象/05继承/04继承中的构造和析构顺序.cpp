#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout<<"Base构造函数！"<<endl;
    }
    ~Base()
    {
        cout<<"Base析构函数！"<<endl;
    }
};

class Son:public Base
{
public:
    Son()
    {
        cout<<"Son构造函数！"<<endl;
    }
    ~Son()
    {
        cout<<"Son析构函数！"<<endl;
    }
};

int main()
{
    //继承中的构造和析构书序如下：
    //先构造父类，再构造子类，析构的顺序与构造的顺序相反
    Son s;
    return 0;
}