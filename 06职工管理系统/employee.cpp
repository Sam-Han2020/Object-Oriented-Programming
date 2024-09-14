#include "employee.h"
//构造函数，初始化职工编号，姓名，部门编号
Employee::Employee(int id,string name,int dId)
{
    this->m_Id=id;
    this->m_Name=name;
    this->m_DeptId=dId;
}

//显示个人信息
void Employee::showInfo()//这里不能写virtual
{
    cout<<"职工编号："<<this->m_Id
        <<"\t职工姓名："<<this->m_Name
        <<"\t岗位："<<this->getDeptName()//不建议直接输出部门编号
        <<"\t岗位职责：007，接受老板和经理的压榨，尽一切努力创造剩余价值"<<endl;
}

//获取岗位名称
string Employee::getDeptName()
{
    return string("小职员");//不写string()也无所谓，编译器会自动转化
}