#include <iostream>
using namespace std;

template <class T> class SmartPointer {
public:
	//��ͨ���캯���� �趨T * ptr��ֵ���������ü�����Ϊ1
	SmartPointer(T * ptr) {
		ref = ptr;
		ref_count = new unsigned;
		*ref_count = 1;
	}

	//ָ�뿽�����캯�����½�һ��ָ�����ж��������ָ��
	//��Ҫ���趨ptr��ref_count
	//��Ϊָ��sptr��ptr��ref_count
	//���ң���Ϊ�½���һ��ptr�����ã��������ü�����һ
	SmartPointer(SmartPointer<T> &sptr) {
		ref = sptr.ref;
		ref_count = sptr.ref_count;
		++(*ref_count);
	}

	//rewrite "="
	SmartPointer<T> & operator = (SmartPointer<T> &sptr) {
        //ͬһ��ָ�룬ֱ�ӷ���
        if (this == &sptr)
            return *this;

        //�������ֵ����1�����ָ�����ֵ-1
		if(*ref_count > 0)
            remove();

        //�Ѿ�ָ��ֵ����ָ��
		ref = sptr.ref;
		ref_count = sptr.ref_count;

        //ָ�����+1
		++(*ref_count);
		return *this;
	}
	~SmartPointer() {
		remove();
	}

	T getValue() {
		return *ref;
	}

	T getCount() {
		return static_cast<T>(*ref_count);
	}

protected:
    //ɾ��ָ��
	void remove() {
		--(*ref_count);

		//�������ֵ����0��������ָ�룬��ִ����������
		if (*ref_count == 0) {
			delete ref;
			delete ref_count;
			ref = NULL;
			ref_count = NULL;
		}
	}
private:
	unsigned * ref_count;    //Ӧ�ü���ֵ
	T * ref;                 //��ָͨ��
};
