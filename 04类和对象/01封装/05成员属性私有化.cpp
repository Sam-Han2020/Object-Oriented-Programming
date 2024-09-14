#include <iostream>
using namespace std;

//成员属性设置为私有
//1.可以自己控制读写权限
//2.对于写权限，可以检测数据的有效性

//设计人类
class Person
{
    public:
    //设置姓名
    void setName(string name)
    {
        m_Name=name;
    }
    //设置年龄
    void setAge(int age)
    {
        age=0;
        if(age<0||age>150) return;//以此检验数据的有效性
        else m_Age=age;
    }
    //设置情人
    void setLover(string Lover)
    {
        m_Lover=Lover;
    }
    //获取姓名
    string getName()
    {
        return m_Name;
    }
    //获取年龄 只读
    int getAge()
    {
        // m_Age=0;//初始化为0岁
        return m_Age; 
    }
    private:
    //姓名 可读可写
    string m_Name;
    //年龄 只读
    int m_Age;
    //情人 只写
    string m_Lover;
};

int main()
{
    Person p;
    p.setName("张三");
    cout<<"姓名为："<<p.getName()<<endl;
    cout<<"年龄为："<<p.getAge()<<endl;
    p.setLover("苍井空");
    return 0;
}