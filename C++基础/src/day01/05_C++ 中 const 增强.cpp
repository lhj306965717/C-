#include<iostream>

using namespace std;

int main_05(void){

	const int a = 10; // 在C++ 中 const是一个真正的常量

	int *p = (int *)&a; // 将一个安全的 赋值给一个不安全的 会报异常（因为C++是强类型语言）
	
	*p = 20; // 在C++ 中无法改变

	// 这是因为 p指针 指向的地址并不是 a的实际地址，而是一个临时的地址

	cout << a << endl; // 10

	cout << *p << endl; // 20


	return 0;
}