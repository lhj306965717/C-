#include <stdio.h>

int g_val; //声明
int g_val = 20; // 没有问题的，这是定义, 但在C++中 不允许

struct student
{
	int age;
	char name[20];

};


// C语言无返回值的函数
f() {
	return 10;
}

void g(int a) {
}

int main_03_03(void) {

	int a = 10;
	int b = 20;

	printf("%d, %d\n", a, b);


    struct student s; // 在C语言中 最前面 必须要 添加 struct

	g(10, 20, 30); // C语言 如果多传参数也是不会报错，但是C++中不允许，因为C++是强类型的语言

	return 0;
}