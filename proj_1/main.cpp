//��дMyString�Ĺ��캯�����������캯�������������͸�ֵ����

#include <iostream>
#include "Mystring.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    char* a = "safas";

    //��ͨ���캯��
    MyString b(a);
    b.print_data();

    //�������캯��
    MyString c(b);
    c.print_data();

    //��ֵ����
    MyString d = c;
    d.print_data();

    return 0;
    //ĩβ�Զ�������������
}
