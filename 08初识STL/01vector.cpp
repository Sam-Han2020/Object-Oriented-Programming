#include <iostream>
using namespace std;
#include <vector>
#include <algorithm> //标准算法头文件


void myPrint(int val)
{
    cout<<val<<endl;
}

void test01()
{
    //创建
    vector<int> v;
    //插入
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    //通过迭代器访问
    // vector<int>::iterator itBegin = v.begin();//其实迭代器，指向容器中第一个元素
    // vector<int>::iterator itEnd = v.end();//结束迭代器，指向容器中最后一个元素的下一个位置
    //第一种遍历方式
    // while(itBegin != itEnd)
    // {
    //     cout<<*itBegin<<endl;
    //     ++itBegin;
    // }

    //第二种遍历方式
    // for(vector<int>::iterator it=v.begin();it!=v.end();++it)
    // {
    //     cout<<*it<<endl;
    // }

    //第三种遍历方式 利用STL中的遍历算法
    for_each(v.begin(),v.end(),myPrint);
}

int main()
{
    test01();
    return 0;
}