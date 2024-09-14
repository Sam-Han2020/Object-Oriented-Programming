#include <iostream>
using namespace std;

// 类模板分文件编写问题以及解决

// 第一种解决方式，直接包含源文件
// #include "person.cpp"

// 第二种解决方式，将.h和.cpp中的内容写到一起，将后缀名改为.hpp文件
// 这是主流的解决方式
#include "person.hpp"

void test01()
{
    Person<string, int> p("Jerry", 10);
    p.showPerson();
}

int main()
{
    test01();
    return 0;
}