#include<iostream>

using namespace std;


class Parent
{
public:

	int a;

	Parent()
	{
		cout << "Parent()..." << endl;
	}

	Parent(int a)
	{
		cout << "Parent(int)..." << endl;
		this->a = a;
	}

	~Parent()
	{
		cout << "~Parent()..." << endl;
	}

};

class Child : public Parent
{
public:

	Child(int a) : Parent(a)
	{
		cout << "Child(int a)" << endl;
		this->a = a;
	}

	void printf()
	{
		cout << a << endl;
	}

	~Child()
	{
		cout << "~Child()..." << endl;
	}
};

int main_03(void)
{
	// 通过new出来的对象，在main函数执行完成后，并不会自动执行析构
	// 是因为 指针 只能通过 delete来释放，堆中的只能手动申请手动释放
	Child * ch = new Child(1);
	delete ch;

	// 通过声明的方式创建的对象，会调用析构函数
	// 因为这种方式是在 栈中 分配内存，当函数结束后，会出栈销毁，自动调用析构
	Child ch1(2);

	// 创建对象的第三种方式
	Child ch2 = Child(3);
	Child(4);


	return 0;
}