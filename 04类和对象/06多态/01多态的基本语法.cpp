#include <iostream>
using namespace std;

//多态

//动物类
class Animal
{
public:
    //虚函数
    // void speak()
    virtual void speak()
    {
        cout<<"动物在说话"<<endl;
    }
    //vfptr virtual function pointer - 虚函数（表）指针
};

//猫类
class Cat:public Animal
{
public:
    //重写：函数返回值类型 函数名 参数列表 完全相同
    virtual void speak()//virtual可以不写
    {
        cout<<"小猫在说话"<<endl;
    }
};

class Dog:public Animal
{
public:    
    void speak()
    {
        cout<<"小狗在说话"<<endl;
    }
};

//执行说话的函数
//地址早绑定，在编译阶段确定函数地址
//如果想执行让猫说话，这个函数的地址就不能提前就绑定，需要在运行阶段进行绑定，地址晚绑定

//动态多态满足条件
//1.有继承关系
//2.子类要重写父类的虚函数

//动态多态使用
//父类的指针或者引用 指向子类对象！！！

void doSpeak(Animal &animal)//父类的指针或者引用 指向子类对象：Animal & animal =cat;
{
    animal.speak();
}

void test01()
{
    Animal animal;
    doSpeak(animal);
    Cat cat;
    doSpeak(cat);//父类引用接收子类对象
    Dog dog;
    doSpeak(dog);
}

void test02()
{
    //复习，只有非静态成员变量存储于类，静态函数和成员，非静态函数都不存储于类
    cout<<"sizeof(Animal)="<<sizeof(Animal)<<endl;
    cout<<"sizeof(Cat)="<<sizeof(Cat)<<endl;
}

int main()
{
    test02();
    return 0;
}