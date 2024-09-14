/*注意：仿函数在使用时与构造函数本质的区别是：构造函数是在声明（定义）类对象的时候调用；而仿函数是已定义好的类对象上进行（重载）调用。*/
#include <iostream>
using namespace std;

//函数调用运算符重载

//打印输出类
class MyPrint
{
public:
    //重载函数调用运算符
    void operator()(string test)
    {
        cout<<test<<endl;
    }
};

void MyPrint02(string a)
{
    cout<<a<<endl;
}

void test01()
{
    MyPrint myPrint;

    myPrint("hello world");//由于使用起来非常类似于函数调用，因此成为仿函数
    MyPrint02("hello world");
}

//仿函数非常灵活，没有一个固定的写法

//加法类
class MyAdd
{
public:
    int operator()(int num1,int num2)
    {
        return num1+num2;
    }
};

void test02()
{
    MyAdd myAdd;
    int ret = myAdd(100,100);
    cout<<"ret = "<<ret<<endl;

    //匿名函数对象
    cout<<MyAdd()(100,100)<<endl;
}

int main()
{
    test02();
    return 0;
}