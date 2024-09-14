#include <iostream>
using namespace std;

//继承方式

//公共继承
class Base1
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son1:public Base1
{
public:
    void func()
    {
        m_A=10;//父类中的公共权限成员，到子类中依然是公共权限
        m_B=10;//父类中的保护权限成员，到了子类中依然是保护权限
        //m_C=10;//错误的，父类中的私有权限成员，子类中访问不到
    }
};

void test01()
{
    Son1 s1;
    s1.m_A=100;
    s1.func();
    // s1.m_B=100;//错误的，到了Son1中，m_B是保护权限，类外访问不到
}

//保护继承
class Base2
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son2:protected Base2
{
public:
    void func()
    {
        m_A=100;//父类中公共成员，到子类中变为保护权限
        m_B=100;//父类中保护成员，到子类中变为保护权限
        // m_C=100;//错误的，父类中的私有成员，子类访问不到
    }
};

void test02()
{
    Son2 s2;
    // s2.m_A=100;//错误的，在Son2中m_A变为了保护权限，类外访问不到
    // s2.m_B=1000;//错误的，在Son2中m_B为保护权限，类外访问不到
    s2.func();
}

class Base3
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son3:private Base3
{
public:
    void func()
    {
        m_A=100;//父类中公共成员，到子类中变为私有成员
        m_B=100;//父类中的保护成员，到子类变为私有成员
        // m_C=100;//错误的，父类中的私有成员，子类访问不到
    }
};

class GrandSon3:public Son3
{
public:
    void func()
    {
        // m_A=1000;//错误的，到了Son3中，m_A变味了私有，即使public继承也访问不到
        // m_B=1000;//错误的，到了Son3中，m_A变味了私有，即使public继承也访问不到
    }
};

void test03()
{
    Son3 s3;
    // s3.m_A=1000;//错误的，到了Son3中变为了私有成员，类外访问不到
    // s3.m_B=1000;//错误的，到了Son3中变为了私有成员，类外访问不到
    s3.func();
}

int main()
{
    return 0;
}