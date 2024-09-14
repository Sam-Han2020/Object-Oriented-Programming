#include <iostream>
using namespace std;
/*内存四区：代码区，全局区，栈区，堆区*/

//全局变量
int g_a=10;
int g_b=10;
//const修饰的全局变量
const int c_g_a=10;
const int c_g_b=10;
int main()
{
    //全局区
    //全局变量、静态变量、常量
    //创建普通局部变量
    int a=10;
    int b=10;
    cout<<"局部变量a的地址为："<<(int)&a<<endl;
    cout<<"局部变量b的地址为："<<(int)&b<<endl;
    cout<<"全局变量g_a的地址为："<<(int)&g_a<<endl;
    cout<<"全局变量g_b的地址为："<<(int)&g_b<<endl;
    //静态变量  在普通变量前面加static，属于静态变量
    static int s_a=10;
    static int s_b=10;
    cout<<"静态变量s_a的地址为："<<(int)&s_a<<endl;
    cout<<"静态变量s_b的地址为："<<(int)&s_b<<endl;
    //常量
    //字符串常量
    cout<<"字符串常量的地址为："<<(int)&"hello world"<<endl;
    //const修饰的变量
    //const修饰的全局变量，const修饰的局部变量
    cout<<"全局常量c_g_a的地址为："<<(int)&c_g_a<<endl;
    cout<<"全局常量c_g_b的地址为："<<(int)&c_g_b<<endl;
    //局部常量
    const int c_l_a=10;//c-const g-global l-local
    const int c_l_b=10;
    cout<<"局部常量c_l_a的地址为："<<(int)&c_l_a<<endl;
    cout<<"局部常量c_l_b的地址为："<<(int)&c_l_b<<endl;
    return 0;
}