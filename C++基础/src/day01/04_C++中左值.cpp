#include <iostream>

using namespace std;

int main_04(void) {

	int a = 10;
	int b = 20;
	int c = 1;

	// C++ 中三目运算符，可以做左值，比在C语言中增强了
	// 其实返回的是一个变量，是具有内存空间的
	(a < b ? a : b) = 50;

	return 0;
}