#include <iostream>

using namespace std;

void funca(int a, int b) {
	cout << a << " : " << b << endl;
}

void funca(int a, int b, int c) {
	cout << a << " : " << b << " : " << c << endl;
}

typedef void(*MY_FUNC)(int, int); // 定义一个函数指针

// 注意：这个主要是 用来创建指针类型的
typedef void (my_func)(int, int); // 定义一个函数类型

int main_04(void) {

	my_func * fc = NULL; // 定义一个函数指针

	fc = funca;

	fc(10, 20);


	MY_FUNC fp = NULL;

	fc = funca;

	fc(100, 200);

	//fc(100, 200, 300); // 报错，无法匹配到三个参数的函数

	//  总结：函数指针不能实现 函数重载

	// 实际上在给函数指针赋值的时候，是会发生函数重载匹配的
	// 在调用函数指针的时候，所调用的函数就已经固定了；


	return 0;
}