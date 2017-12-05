#include <iostream>

using namespace std;


class Test
{
private:
	int a;
public:

	Test(int a)
	{
		this->a = a;
	}

	// 首先：函数并不在对象内存中，函数在 代码区
	// 但是 对象是怎么通过函数返回值的呢？

	// 其实编译器在编译后变成 int getA(Test* const pthis){ }
	// 通过将对象的地址隐藏的传递进来了，所以对象中的函数才能返回对象中的变量
	// 而且这个指针是 一个指针常量 ，只能修改其指向地址的值，不能修改指向的地址
	int getA(/*Test* const this*/)
	{
		this->a = 100;

		return a;
	}

	// 结合静态总结：

	// 1.静态成员函数的意义，不在于信息共享，数据沟通，而在于管理静态数据成员，完成对静态数据成员的封装

	// 2.静态成员函数只能访问静态数据成员。原因：非静态成员函数，在调用是this指针当作参数传进
	//   而非静态成员函数属于类，而不属于对象，没有this指针

	// 跟java 一样，静态函数 中不能访问非静态 成员变量或者方法
};


class Text
{
public:
	Text(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	void print()
	{
		cout << "a=" << this->a << "  b=" << this->b << endl;
	}

	int getA()
	{
		return this->a;
	}

	int getB()
	{
		return this->b;
	}

	// 提供成员函数
	Text TextAdd(Text &another)
	{
		Text temp(this->a + another.getA(), this->b + another.getB());
		return temp;
	}

	// 实现 +=
	Text& TextAdd2(Text &another)
	{
		this->a += another.a;
		this->b += another.b;

		// return this;  注意：这里不能返回 this, 因为 this 是一个指针，

		return *this; // 只能返回这个指针所指向的值 ----> 这个对象
	}

private:
	int a;
	int b;
};

// 提供全局的相加函数
Text TextAdd(Text &t1, Text &t2)
{
	Text temp(t1.getA() + t2.getA(), t1.getB() + t2.getB());
	return temp;
}

int main_05(void)
{
	Text t1(10, 20);
	Text t2(100, 200);

	Text sun = TextAdd(t1, t2);

	sun.print();

	cout << "*************************************" << endl;

	Text t3 = t1.TextAdd(t2);

	t3.print();

	cout << "*************************************" << endl;

	// 由于返回的是当前对象，所以可以链式调用
	t1.TextAdd2(t2).TextAdd2(t2).print();

	return 0;
}