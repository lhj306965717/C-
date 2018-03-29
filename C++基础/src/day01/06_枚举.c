#include <stdio.h>

enum season  //定义枚举类型，类似结构体
{
	A,
	B,
	C = 110,
	D,
	E
};

int main(void) {

	// 在C语言中，使用的不是 枚举 中值不会报错，但是在C++ 中不行
	enum season s = 10; // 定义枚举变量

	printf("%d\n", s); // 枚举使用

	enum season a = D;

	// 直接使用
	printf("%d\n", B); 
	printf("%d\n", a);

	return 0;
}