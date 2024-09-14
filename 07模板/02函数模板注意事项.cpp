#include <iostream>
using namespace std;

// 函数模板注意事项

template <class T>
void mySwap(T &a, T &b)
{
    T t = a;
    a = b;
    b = t;
}

// 1.自动类型推导，必须推导出一致的数据类型T才可以使�?
// 2.模板必须要确定出T的数据类型，才可以使�?

int main()
{
    return 0;
}