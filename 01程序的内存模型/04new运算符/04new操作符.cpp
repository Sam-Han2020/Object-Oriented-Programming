#include <iostream>
using namespace std;
int* func()
{
    //在堆区创建整型数据，以此避免在栈区创建数据而被释放
    //new返回是该数据类型的指针
    int *p = new int(10);
    return p;
}
void test01()
{
    int *p=func();
    cout<<*p<<endl;
    cout<<*p<<endl;
    cout<<*p<<endl;
    //堆区的数据由程序员管理开辟，程序员管理释放
    //如果想释放堆区的数据，利用关键字delete
    delete p;
    cout<<*p<<endl;//内存已经被释放，再次访问就是非法操作，会乱码
}
void test02()
{
    //创建10整型数据的数组，在堆区
    int *arr = new int[10];//代表数组有10个元素
    for(int i=0;i<10;i++)
    {
        arr[i]=i+100;//给10个元素赋值
    }
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<endl;
    }
    //释放堆区数组
    //释放数组的时候，要加[]才可以
    delete[] arr;
}
int main()
{
    test02();
    return 0;
}