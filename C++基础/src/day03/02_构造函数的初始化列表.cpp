#include <iostream>

using namespace std;

// 在C++ 中 的一个文件 相当于 java的一个类

// C++ 中 为什么static声明只能在本文件中使用，有点类似java中类，java中 static是属于类中的，
// 而C++是属于当前这个文件的，所以把当前文件当成一个类来使用

class A
{
public:
	A(int a)
	{
		this->m_a = a;
		cout << "A 构造函数 ：" << a << endl;
	}

	~A()
	{
		cout << "~A 析构" << endl;
	}

	A(const A& a)
	{
		this->m_a = a.m_a;
		cout << "A 拷贝构造" << endl;
	}

	void printA()
	{
		cout << "a=" << m_a << endl;
	}

private:
	int m_a;
};

// 构造函数的初始化列表
class B
{
public:
	// 如果像初始化一个类型的对象声明的话，就得把参数这样写才行
	B(A &a1, A &a2, int b) : m_a1(a1)/*这样写叫初始化列表*/, m_a2(a2) // 这样初始化就是拷贝构造初始化
	{
		this->m_b = b;
		//this->m_a1 = a1; // 这样只是浅拷贝，只是赋值，无法使用 a1 引用来初始化

		// 注意：如果一个类中含有 一种对象类型，那么是无法通过传递进来的参数进行初始化这个对象类型变量

		cout << "B 构造函数 ---> B(A &a1, A &a2, int b)" << endl;
	}

	~B()
	{
		cout << "~B" << endl;
	}

	// 构造对象成员的顺序跟初始化列表顺序无关
	// 而是跟成员对象的定义顺序有关
	B(int a1, int a2, int b) : m_a1(a1), m_a2(a2) // 此时调用的是构造函数
	{
		// 注意：一个类中存在 一个对象的 变量，那么在构造函数中，必须要进行初始化
		
		cout << "B(int a1, int a2, int a3)" << endl;

		m_b = b;

		cout << "B 构造函数 ---> B(int a1, int a2, int b)" << endl;
	}

	void printB()
	{
		cout << "b=" << m_b << endl;
		m_a1.printA();
		m_a2.printA();
	}

private:
	int m_b;
	A m_a1; // 这是两个成员对象，如果要创建 B对象，那么必须先给 这个变量对象赋值
	A m_a2;

	// 因为，只有当 调用了构造函数后，才会开辟空间
	//int m_b = 10; // 注意：这样写是语法错误的，不能这样写，只能在构造函数中去初始化，不报错是编译器给优化掉了

	//const int m_b; // 常量的 初始化也不能直接在 这里赋值初始化 ，只能写在构造函数的 初始化列表里
};

static void test1()
{

	A a1(10), a2(100);

	B b(a1, a2, 1000);

	b.printB();
}

static void test2()
{
	B b(10, 20, 300);

	b.printB();

	B(10, 20, 30); // 匿名对象,然后会被立刻析构
}

int main_02(void)
{
	//test1();

	test2();

	return 0;
}