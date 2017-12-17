#include<iostream>


using namespace std;

// 重载小括号

class Sqr
{
private:
	int a;

public:

	Sqr(int a)
	{
		this->a = a;
	}

	int operator()(int value)
	{
		return value * value;
	}
};



class A
{
private:
	int a;

public:
	// 默认构造函数
	A() 
	{
		cout << "无参构造函数" << endl;
	}

	A(int a)
	{
		cout << "A的构造函数" << endl;
		this->a = a;
	}

	// 注意：size_t 就是 unsigned int
	// 重载的new操作符 依然会触发对象的构造函数
	void * operator new(size_t size)
	{
		// 这里的大小是4，为什么呢，因为这个类中的 只有一个 int 类型的变量
		// 如果再添加其他变量，那么这个size的大小就不是4了
		cout << "重载了new操作符 : " << size << endl;
		return malloc(size);
	}

	// 重载 delete
	void operator delete(void *p)
	{
		cout << "重载了 delete 操作符" << endl;
		free(p);
	}

	// 注意：这里重载的 是 " new[] "
	void * operator new[](size_t size)
	{
		cout << "重载了 new [] 操作符 : " << size << endl;
		return malloc(size);
	}

	void operator delete[](void * p)
	{
		cout << "重载了 delete[] 操作符" << endl;
		free(p);
	}

	~A()
	{
		cout << "A 的析构函数" << endl;
	}
};

int main_02(void)
{
	Sqr s(10);

	// 我们将一个对象 当成一个普通函数来调用
	// 称这种对象是仿函数或者伪函数
	int a = s(2);// 注意：这里不是调用构造函数，是调用一个无参的函数


	A *p = new A(10); // 10 这个参数，是为了触发 单个参数的构造函数
	//p->operator new(sizeof(A)); // 实际上他是这样触发的

	delete p; // 释放


	A *arr = new A[3];
	//arr->operator new[](sizeof(A) * 3); // 这是实际的调用方式

	delete[] arr; // 释放

	return 0;
}

// 注意：不推荐 重写 && || ，因为重写了，不会实现短路功能，既&& 如果第一个参数为false，那么后面个参数还是会执行(短路功能是不会执行的)