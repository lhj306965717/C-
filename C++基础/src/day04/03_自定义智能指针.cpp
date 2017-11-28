#include <iostream>

#include <memory>

using namespace std;

class B
{
private:
	int a;
public:
	B(int a)
	{
		this->a = a;
	}

	void func()
	{
		cout << "调用 func 函数" << endl;
	}

	~B()
	{
		cout << "析构B" << endl;
	}
};

class MyAutoPtr
{
private:
	B *ptr;
public:
	MyAutoPtr(B *ptr)
	{
		this->ptr = ptr;
	}

	~MyAutoPtr()
	{
		if (this->ptr != NULL)
		{
			delete this->ptr;
			this->ptr = NULL;
			this->ptr = nullptr; // 跟上面的效果是一样的
		}

		cout << "触发析构 MyAutoPtr" << endl;
	}

	// 重写 -> 操作符
	B * operator ->()
	{
		return this->ptr;
	}

	// 重写 * 操作符
	B & operator *()
	{
		return *this->ptr;
	}
};

int main_03(void)
{
	//int *p = new int;
	//// 这个就是一种数据类型，是一个指向int类型的指针
	//auto_ptr<int> ptr(new int);

	//*ptr = 20;

	//B *pa = new B(10);
	//pa->func(); // 其实 类，就是 一个结构体
	//delete pa;


	//auto_ptr<B> ptra(new B(100));
	//ptra->func();
	////  不需要手动释放


	cout << "++++++++++++++++++++++++++++++++" << endl;

	// 如果 不屏蔽上面代码，打印出来的结果会有干扰

	MyAutoPtr myPtr(new B(1000));
	myPtr->func();

	(*myPtr).func();

	return 0;
}