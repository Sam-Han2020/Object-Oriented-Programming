#include <iostream>
using namespace std;

// 实现通用的对数组排序的函数
// 规则 从大到小 选择排序
// 测试 char int

// 交换函数模板
template <class T>
void mySwap(T &a, T &b)
{
    T t = a;
    a = b;
    b = t;
}

// 打印数组模板
template <class T>
void printArray(T arr[], int len)
{
    for (int i = 0; i < len; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// 排序算法
template <class T>
void mySort(T arr[], int len)
{
    for (int i = 0; i < len; ++i)
    {
        int max = i; // 认定的最大值的下标
        for (int j = i + 1; j < len; ++j)
        {
            // 认定的最大值 比 遍历出的数值要小 说明j下标的元素才是真正的最大值
            if (arr[max] < arr[j])
                max = j;
        }
        if (max != i)
            mySwap(arr[max], arr[i]);
    }
}

void test01()
{
    char charArr[] = "badcfe";
    int len = sizeof(charArr) / sizeof(char);
    mySort<char>(charArr, len);
    printArray(charArr, len);
}

void test02()
{
    // 测试int数组
    int intArr[] = {7, 5, 1, 3, 9, 2, 4, 6, 8};
    int num = sizeof(intArr) / sizeof(int);
    mySort(intArr, num);
    printArray(intArr, num);
}

int main()
{
    test02();
    return 0;
}