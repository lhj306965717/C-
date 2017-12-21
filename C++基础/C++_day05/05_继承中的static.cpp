#include<iostream>

using namespace std;

class A
{
public:
	static int a;

};

int A::a = 10; // 静态成员变量初始化需要在外面进行

class B : public A
{

};

int main_05(void)
{
	A a1;

	cout << a1.a << endl;

	A::a = 300;

	cout << A::a << endl;

	B b1;

	cout << b1.a << endl;


	// 跟java一样，静态属于 类，并不属于 对象，但是 静态一样会被继承
	// 其他都一样，除了 静态属于类

	return 0;
}