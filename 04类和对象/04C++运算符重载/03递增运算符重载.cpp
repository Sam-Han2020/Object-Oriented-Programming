#include <iostream>
using namespace std;

//重载递增运算符

//自定义整型
class MyInterger
{
    friend ostream& operator<<(ostream& cout,MyInterger myint);
public:
    MyInterger()
    {
        m_Num=0;
    }

    //重载前置++运算符
    MyInterger& operator++()//返回引用是为了一直对一个数据进行递增操作
    {
        //先进行++运算
        m_Num++;
        //再将自身做返回
        return *this;
    }
    //重载后置++运算符
   MyInterger operator++(int)//int 代表一个占位参数，可以用于区分前置和后置递增
    {
        //先 记录当时结果
        MyInterger temp=*this;
        //后 递增
        m_Num++;
        //最后将记录结果返回
        return temp;
    }//后置递增一定返回值！！！

private:
    int m_Num;
};

//重载左移运算符
ostream& operator<<(ostream& cout,MyInterger myint)
{
    cout<<myint.m_Num;
    return cout;
}

void test01()
{
    MyInterger myint;
    cout<<++myint<<endl;
}

void test02()
{
    MyInterger myint;
    cout<<myint++<<endl;
    cout<<myint<<endl;
}

int main()
{
    test01();
    test02();
    return 0;
}