#include <iostream>
#include <string>
using namespace std;

//���Ӵ���next����
int* getnext_arr(string B)
{
    int len = B.length();
    int* next = new int[len];
    next[0] = -1;
    int k = -1;
    int j = 0;
    while(j < len-1){
        //p[k]��ʾǰ׺��p[j]��ʾ��׺
        if (k == -1 || B[j] == B[k])
        {
            ++k;
            ++j;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
    return next;
}

//ƥ���ַ�����δƥ������next������������ƶ�
int getIndex(string A, string B)
{
    if(A == "" || B == "" || B.length() < 1 || B.length() > A.length())
        return -1;

    int Ai = 0, Bi = 0;
    int len = B.length();
    int* next = new int[len];
    next = getnext_arr(B);

    while(Ai<A.length() && Bi<B.length()){
        if(A[Ai] == B[Bi]){
            ++ Ai;
            ++ Bi;
        }
        else if(next[Bi] == -1){
            ++ Ai;
        }
        else{
            Bi = next[Bi];
        }
    }
    return Bi == B.length()? Ai-Bi:-1;
}

int main()
{
    cout << "Hello world!" << endl;

    string A,B;
    while(cin >> A >> B){
        cout << getIndex(A,B) << endl;
    }

    return 0;
}
