#include "Mystring.h"
#include <cstdlib>
#include <cstring>
using namespace std;

//���캯��
MyString::MyString(const char *str):m_data(nullptr)
{
    char *p = nullptr;
    if(str == nullptr){
        p = new char[1];
        if(p == nullptr){
            cout << "allocated failed!" << endl;
            exit(-1);
        }
        else{
            *p = '\0';
            m_data = p;
            p = nullptr;
        }
    }
    else{
        size_t length = strlen(str);
        p = new char[length+1];
        if(p == nullptr){
            cout << "allocated failed!" << endl;
            exit(-1);
        }
        else{
            strcpy(p,str);    //ע��strcpy��copyĩβ��/0
            m_data = p;
            p = nullptr;
        }
    }
}

//�������캯��
MyString::MyString(const MyString &other)
{
    char *p = nullptr;
    size_t length = strlen(other.m_data);

    p = new char[length+1];
    if(p == nullptr){
        cout << "allocated failed!" << endl;
        exit(-1);
    }
    else{
        strcpy(p,other.m_data);    //ע��strcpy��copyĩβ��/0
        m_data = p;
        p = nullptr;
    }
}

//��������
MyString::~MyString(void)
{
    if(m_data != nullptr){
        delete[] m_data;
        m_data = nullptr;
    }
}

//��ֵ����
MyString & MyString::operator = (const MyString & other)
{
    if(this == &other)
        return *this;

    char* p = nullptr;
    size_t length = strlen(other.m_data);
    p=new char[length+1];

    if(p == nullptr){
        cout << "allocated failed!" << endl;
        return *this;
    }
    else{
        strcpy(p,other.m_data);    //ע��strcpy��copyĩβ��/0
        m_data = p;
        p = nullptr;
    }

    return *this;
}

void MyString::print_data()
{
    cout << this->m_data << endl;
}



