#include <iostream>

class MyString
{
public:
    MyString(const char *str = nullptr);
    MyString(const MyString &other);
    ~MyString(void);
    MyString & operator = (const MyString & other);
    void print_data();
private:
    char *m_data;
};
