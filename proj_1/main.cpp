//编写MyString的构造函数、拷贝构造函数、析构函数和赋值函数

#include <iostream>
#include "Mystring.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    char* a = "safas";

    //直接初始化，进行构造函数的匹配，这里选择的是普通的构造函数
    MyString b(a);
    b.print_data();
    cout << endl;

    //直接初始化，进行构造函数的匹配，这里选择的是拷贝构造函数
    MyString c(b);
    c.print_data();
    cout << endl;

    //拷贝初始化，直接调用拷贝构造函数，完成两个对象直接的拷贝初始化
    MyString d = c;
    d.print_data();
    cout << endl;

    //拷贝赋值运算符，发生在赋值操作上，不是初始化的操作上，所以先定义变量，在使用赋值操作时调用
    MyString e;
    e = d;

    return 0;
    //末尾自动调用析构函数
}
