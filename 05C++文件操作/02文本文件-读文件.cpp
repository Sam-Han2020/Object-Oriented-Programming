#include <iostream>
using namespace std;
#include <fstream>

//文本文件 读文件
void test01()
{
    //1.包含头文件

    //2.创建流对象
    ifstream ifs;
    //3.打开文件，并且判断是否打开成功
    ifs.open("test.txt",ios::in);

    if(!(ifs.is_open())){
        cout<<"文件打开失败"<<endl;
        return;
    }
    //4.读数据

    //第一种
    // char buf[1024]={0};
    // while(ifs>>buf)
    // {
    //     cout<<buf<<endl;
    // }

    //第二种
    // char buf[1024]={0};
    // while(ifs.getline(buf,sizeof(buf)))
    // {
    //     cout<<buf<<endl;
    // }

    //第三种,前提注释掉前面两个方法
    string buf;
    while(getline(ifs,buf))
    {
        cout<<buf<<endl;
    }

    //第四种,不推荐，因为一个一个读取没有一行一行快
    char c;
    while((c=ifs.get())!=EOF)//EOF end of file
    {
        cout<<c;
    }
    //5.关闭文件
    ifs.close();


}

int main()
{
    test01();
    return 0;
}