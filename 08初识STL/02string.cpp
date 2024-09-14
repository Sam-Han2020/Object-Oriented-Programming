#include <iostream>
using namespace std;
#include <string>

void test01()
{
    string s1;
    const char* str="Hello World";
    string s2(str);
    cout<<s2<<endl;
    string s3(s2);
    cout<<s3<<endl;
    string s4(10,'a');
    cout<<s4<<endl;
}

void test02()
{
    string str1;
    str1="hello world";
    cout<<"str1 = "<<str1<<endl;
    string str2=str1;
    string str3;
    str3='a';
    cout<<str3<<endl;
    string str4;
    str4.assign("hello C++");
    cout<<str4<<endl;
    string str5;
    str5.assign("hello C++",5);
    cout<<str5<<endl;
    string str6;
    str6.assign(str5);
    cout<<str6<<endl;
    string str7;
    str7.assign(10,'w');
    cout<<str7<<endl;
}

void test03()
{
    string str1="ÎÒ";
    str1+="°®ÍæÓÎÏ·";
    cout<<str1<<endl;
    str1+=':';
    cout<<str1<<endl;
    string str2="LOL DNF";
    str1=str2;
    cout<<str1<<endl;
    string str3="I";
    str3.append(" love",3);
    cout<<str3<<endl;
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}