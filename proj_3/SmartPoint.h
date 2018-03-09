#include <iostream>
using namespace std;

template <class T> class SmartPointer {
public:
	//普通构造函数， 设定T * ptr的值，并将引用计数设为1
	SmartPointer(T * ptr) {
		ref = ptr;
		ref_count = new unsigned;
		*ref_count = 1;
	}

	//指针拷贝构造函数，新建一个指向已有对象的智能指针
	//需要先设定ptr和ref_count
	//设为指向sptr的ptr和ref_count
	//并且，因为新建了一个ptr的引用，所以引用计数加一
	SmartPointer(SmartPointer<T> &sptr) {
		ref = sptr.ref;
		ref_count = sptr.ref_count;
		++(*ref_count);
	}

	//rewrite "="
	SmartPointer<T> & operator = (SmartPointer<T> &sptr) {
        //同一个指针，直接返回
        if (this == &sptr)
            return *this;

        //如果计数值大于1，则旧指针计数值-1
		if(*ref_count > 0)
            remove();

        //把旧指针值给新指针
		ref = sptr.ref;
		ref_count = sptr.ref_count;

        //指针计数+1
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
    //删除指针
	void remove() {
		--(*ref_count);

		//如果计数值等于0，则销毁指针，并执行析构函数
		if (*ref_count == 0) {
			delete ref;
			delete ref_count;
			ref = NULL;
			ref_count = NULL;
		}
	}
private:
	unsigned * ref_count;    //应用计数值
	T * ref;                 //普通指针
};
