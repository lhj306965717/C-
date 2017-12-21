#include<iostream>

using namespace std;

class Parent
{
public:
	int a;

	Parent(int a)
	{
		cout << "+++++++++" << endl;
		this->a = a;
	}
};

class Child : public Parent
{
public:
	int a;

	// 也可以大家共同使用同一个初始值
	Child(int p_a, int c_a) : Parent(p_a)
	{
		this->a = c_a;
	}

	void printf()
	{
		// 一旦出现同名的变量名，直接使用域操作符访问
		cout << Parent::a << endl;
		cout << a << endl;
	}
};

int main_04(void)
{
	Child* ch = new Child(10, 100);
	cout << ch->a << endl;
	// 也是通过域操作符来直接访问父类中的方法
	// 非常类似 java中的 super
	cout << ch->Parent::a << endl;

	// 第二种方式，用父引用来访问
	Parent* parent = ch;
	cout << parent->a << endl;


	return 0;
}