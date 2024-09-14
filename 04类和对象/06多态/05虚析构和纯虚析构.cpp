#include <iostream>
using namespace std;

//虚析构和纯虚析构

class Animal
{
public:
    Animal(){cout<<"Animal构造函数调用"<<endl;}
    //改为虚析构，就可以调用Cat析构函数
    //利用虚析构，可以解决父类指针释放子类对象时不干净的问题
    // virtual ~Animal(){cout<<"Animal析构函数调用"<<endl;}
    //纯虚析构，也需要代码实现，在类外,因为父类也可能有数据声明到堆区
    //有了纯虚析构，这个类也属于抽象类，无法实例化对象
    virtual ~Animal()=0;
    virtual void speak()=0;

};

Animal::~Animal()
{
    cout<<"Animal析构函数调用"<<endl;
}

class Cat:public Animal
{
public:
    Cat(string name)
    {
        cout<<"Cat构造函数调用"<<endl;
        m_Name = new string(name);
    }
    virtual void speak()
    {
        cout<<*m_Name<<"小猫在说话"<<endl;
    }
    ~Cat()
    {
        if(m_Name!=NULL) 
        {
            cout<<"Cat析构函数调用"<<endl;
            delete m_Name;
            m_Name=NULL;
        }
    }
    string *m_Name;
    
};

void test01()
{
    Animal * animal =new Cat("Tom");//父类指针指向子类对象
    //当你用animal指针去接收喵的引用的时候，其实你接收的只是喵继承了动物类后的那一部分
    animal->speak();
    //父类指针在析构的时候，不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄漏
    delete animal;
}

int main()
{
    test01();
    return 0;
}