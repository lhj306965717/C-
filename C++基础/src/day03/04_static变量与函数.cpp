#include <iostream>

using namespace std;

// 总结：
// 静态成员属于类作用域，但不属于类对象，和普通的static变量一样，程序一运行就分配内存并初始化，生命周期和程序一致。
// 所以，在类的构造函数里初始化static变量显然是不合理的。
// 静态成员其实和全局变量地位是一样的，只不过编译器把它的使用限制在类作用域内（不是类对象，它不属于类对象成员），
// 要在类的定义外（不是类作用域外）初始化。


class Test
{
public:
	static int m_b;
	static const int m_c = 1000; // 只有静态常量整型数据成员才可以在类中初始化，其他都不行

	static int getM_b()
	{
		return m_b;
	}
private:
	static int m_a; // 静态修饰成员变量
	// 静态是属于这个类的，不属于单个对象，这个跟java一样，因为静态在静态区
};

// 注意:静态成员变量的初始化，一定要在类的外边
int Test::m_a = 10;
int Test::m_b = 100; 

// 注意： “::” 两个冒号的是作用域名


int main_04(void)
{

	// C++ 的 static 与 C 的一样，保留到了C++

	Test::m_b = 200; // 可以直接通过类名来访问

	// 静态初始化在 对象之前 ，因为 静态跟 对象没有关系，静态的分配空间是在静态区


	cout << Test::getM_b() << endl;

	cout << Test::m_c << endl;


	return 0;
}