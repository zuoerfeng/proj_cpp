//��дMyString�Ĺ��캯�����������캯�������������͸�ֵ����

#include <iostream>
#include "Mystring.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    char* a = "safas";

    //ֱ�ӳ�ʼ�������й��캯����ƥ�䣬����ѡ�������ͨ�Ĺ��캯��
    MyString b(a);
    b.print_data();
    cout << endl;

    //ֱ�ӳ�ʼ�������й��캯����ƥ�䣬����ѡ����ǿ������캯��
    MyString c(b);
    c.print_data();
    cout << endl;

    //������ʼ����ֱ�ӵ��ÿ������캯���������������ֱ�ӵĿ�����ʼ��
    MyString d = c;
    d.print_data();
    cout << endl;

    //������ֵ������������ڸ�ֵ�����ϣ����ǳ�ʼ���Ĳ����ϣ������ȶ����������ʹ�ø�ֵ����ʱ����
    MyString e;
    e = d;

    return 0;
    //ĩβ�Զ�������������
}
