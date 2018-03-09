#include <iostream>
#include "SmartPoint.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int *aaa = new int(1024);
    int *bbb = new int(1111);

    SmartPointer<int> a(aaa);
    cout << a.getCount() << endl;
    cout << endl;

    SmartPointer<int> b = a;
    cout << a.getCount() << endl;
    cout << b.getCount() << endl;
    cout << endl;

    SmartPointer<int> c(bbb);
    b = c;
    cout << b.getCount() << endl;
    cout << c.getCount() << endl;
    cout << a.getCount() << endl;

    return 0;
}
