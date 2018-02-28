//编写MyString的构造函数、拷贝构造函数、析构函数和赋值函数

#include <iostream>
#include "Mystring.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    char* a = "safas";

    //普通构造函数
    MyString b(a);
    b.print_data();

    //拷贝构造函数
    MyString c(b);
    c.print_data();

    //赋值函数
    MyString d = c;
    d.print_data();

    return 0;
    //末尾自动调用析构函数
}
