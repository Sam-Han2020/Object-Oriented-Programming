#include <iostream>
using namespace std;

//设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号

//设计学生类
class Student
{
    //公共权限
    public:
    //类中的属性和行为，我们统一称为“成员”
    //属性=成员属性=成员变量
    //属性
    string m_name;
    string m_id;
    //行为=成员函数=成员方法
    //行为
    //给姓名和学号赋值
    void setName(string name)
    {
        m_name=name;
    }
    void setID(string id)
    {
        m_id=id;
    }
    //显示姓名和学号
    void PrintStu()
    {
        cout<<"姓名："<<m_name<<'\t'<<"学号："<<m_id<<endl;
    }
};

int main()
{
    //创建一个具体的学生，实例化对象
    Student s1;
    //给s1对象进行属性赋值操作
    s1.m_name="吴凡";
    s1.m_id="114514";
    s1.PrintStu();

    Student s2;
    s2.setName("dog大王");
    s2.setID("1919810");
    s2.PrintStu();

    return 0;
}