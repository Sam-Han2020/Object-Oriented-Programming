#include <iostream>
using namespace std;

//普通实现页面

// //Java页面

// class Java
// {
// public:
//     void header()
//     {
//         cout<<"首页、公开课、登录、注册...(公共头部)"<<endl;
//     }
//     void footer()
//     {
//         cout<<"帮助中心、交流合作、站内地图...(公共底部)"<<endl;
//     }
//     void left()
//     {
//         cout<<"Java、Python、C++...(公共分类列表)"<<endl;
//     }
//     void content()
//     {
//         cout<<"Java学科视频"<<endl;
//     }
// };

// //Python页面

// class Python
// {
// public:
//     void header()
//     {
//         cout<<"首页、公开课、登录、注册...(公共头部)"<<endl;
//     }
//     void footer()
//     {
//         cout<<"帮助中心、交流合作、站内地图...(公共底部)"<<endl;
//     }
//     void left()
//     {
//         cout<<"Java、Python、C++...(公共分类列表)"<<endl;
//     }
//     void content()
//     {
//         cout<<"Python学科视频"<<endl;
//     }
// };

// //C++页面

// class Cpp
// {
// public:
//     void header()
//     {
//         cout<<"首页、公开课、登录、注册...(公共头部)"<<endl;
//     }
//     void footer()
//     {
//         cout<<"帮助中心、交流合作、站内地图...(公共底部)"<<endl;
//     }
//     void left()
//     {
//         cout<<"Java、Python、C++...(公共分类列表)"<<endl;
//     }
//     void content()
//     {
//         cout<<"C++学科视频"<<endl;
//     }
// };

//继承实现页面

//继承的好处，减少重复的代码
//语法 class 子类名 : 继承方式  父类
//子类，也称为：派生类
//父类，也称为：基类

//公共页面类
class BasePage
{
public:
    void header()
    {
        cout<<"首页、公开课、登录、注册...(公共头部)"<<endl;
    }
    void footer()
    {
        cout<<"帮助中心、交流合作、站内地图...(公共底部)"<<endl;
    }
    void left()
    {
        cout<<"Java、Python、C++...(公共分类列表)"<<endl;
    }
};

//Java页面
class Java:public BasePage
{
public:    
    void content()
    {
        cout<<"Java学科视频"<<endl;
    }
};

//Python页面
class Python:public BasePage
{
public:    
    void content()
    {
        cout<<"Python学科视频"<<endl;
    }
};

//C++页面
class Cpp:public BasePage
{
public:    
    void content()
    {
        cout<<"C++学科视频"<<endl;
    }
};


void PrintPage(Java ja)
{
    cout<<"Java下载视频页面如下："<<endl;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    cout<<"-------------------------"<<endl;
}

void PrintPage(Python ja)
{
    cout<<"Python下载视频页面如下："<<endl;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    cout<<"-------------------------"<<endl;
}

void PrintPage(Cpp ja)
{
    cout<<"C++下载视频页面如下："<<endl;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    cout<<"-------------------------"<<endl;
}

void test01()
{
    Java ja;
    Python py;
    Cpp cpp;
    PrintPage(ja);
    PrintPage(py);
    PrintPage(cpp);
}


int main()
{
    test01();
    return 0;
}