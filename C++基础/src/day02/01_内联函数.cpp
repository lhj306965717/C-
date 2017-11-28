#include <iostream>

using namespace std;

void pringAB(int a, int b) {
	cout << "a=" << a << "b=" << b << endl;
}

// 不停的重复调用，
// 可以通过 inline 声明，类似 宏定义声明的函数，直接在for循环中展开
// 相当与
inline void printAC(int a, int b){
	cout << "a=" << a << "  b=" << b << endl;
}

int main_01(void) {

	int a = 10, b = 20;

	for (int i = 0; i < 100; i++)
	{
		a++;
		b++;

		//pringAB(a, b);

		// 这样做的好处是，减少 函数的 压栈和出栈，减少性能损耗

		printAC(a, b); // 在编译的时候，会把printAC中的代码展开

		// 也只是 这个函数代码少的时候，编译器才会这么做，如果太多(写了inline也没用 )，也不会这么做
	}

	return 0;
}