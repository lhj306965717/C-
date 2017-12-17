#include<iostream>

using namespace std;

namespace B
{
	int a = 10;
	int b = 20;

	void f()
	{
		cout << "f()" << endl;
	}

	namespace A
	{
		int b = 200;
		int a = 100;
		int c = 300;
	}

	using namespace A; // 必须要声明 ，否则下面的函数不能被使用

	void g()
	{
		cout << c << endl; // 不能直接使用，因为在不同的命名空间中
	}
}

<<<<<<< HEAD
int main_test(void)
=======
int main_0(void)
>>>>>>> 13b84ed66fdc4bd521c8f8bcaf28af25434812aa
{
	using namespace B;

	int temp = B::a + B::b;

	bool b;

	if (temp > 0) 
	{
		b = true;
	}
	else
	{
		b = false;
	}

	cout << "bool b= " << b << endl;


	int value = B::A::a > B::a ? B::A::a : B::a;

	cout << "value= " << value << endl;


	return 0;
}