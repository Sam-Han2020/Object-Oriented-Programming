#include <iostream>
using namespace std;

//继承中的对象模型

class Base
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son:public Base
{
public:
    int m_D;
};

//利用开发人员命令提示工具查看对象模型
//跳转盘符 D:
//跳转文件路径 cd 具体路径下
//查看命名
//c1 /d1 reportSinglsClassLayout类名 文件名

void test01()
{
    //父类中所有非静态成员属性都会被子类继承下去
    //父类中私有成员属性，是被编译器隐藏了，因此是访问不到，但是确实被继承下去了
    cout<<"sizeof(Son)="<<sizeof(Son)<<endl;//sizeof(Son)=16
}

int main()
{
    test01();
    return 0;
}