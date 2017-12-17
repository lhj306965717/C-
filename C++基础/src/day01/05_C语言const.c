#include <stdio.h>

int main_05(void) {

	const int a = 10;  // 在C语言中 const声明的是 伪常量

	int *p = &a;

	*p = 20;

	printf("%d\n", a); // 可以修改是一个伪常量

	return 0;
}