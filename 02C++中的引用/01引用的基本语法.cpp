//引用：给变量起别名
//语法：数据类型 &别名 = 原名
#include <iostream>
using namespace std;

int main()
{
    int a=0;
    //创建引用
    int &b=a;//引用必须要初始化
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    b=20;
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    return 0;
}