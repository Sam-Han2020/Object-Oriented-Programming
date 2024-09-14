#include <iostream>
using namespace std;
#include <fstream>//头文件包含

//文本文件 写文件

int main()
{
    //1.包含头文件fstream

    //2.创建流对象

    ofstream ofs;

    //3.指定打开方式
    ofs.open("test.txt",ios::out);

    //4.写内容
    ofs<<"姓名：张三"<<endl;
    ofs<<"姓名：男"<<endl;
    ofs<<"年龄：18"<<endl;

    //5.关闭文件
    ofs.close();
    
    return 0;
}