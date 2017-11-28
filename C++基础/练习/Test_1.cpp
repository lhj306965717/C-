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

	using namespace A; // ����Ҫ���� ����������ĺ������ܱ�ʹ��

	void g()
	{
		cout << c << endl; // ����ֱ��ʹ�ã���Ϊ�ڲ�ͬ�������ռ���
	}
}

int main(void)
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