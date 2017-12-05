#include <iostream>

using namespace std;

int g_val;  // bss段
// 因为C++是强类型的语言，对全局变量的定义检测能力增强了
//int g_val = 20;  //data段  // 报错，在C++ 中全局变量并没有定义与声明这种写法

struct student
{
	char name[20];
	int age;
};

void test() {

	// C++ 中新增加的 布尔类型
	bool flag = true;

	// true 取值1，false 取值为0，且只能取这两个值
	cout << flag << endl;
}

int main_03(void) {

	// 1.
	// 随处声明随处使用，但是在C语言中，只能是先声明再使用，这是C++的增强
	// C语言中不允许这样写
	for (int i = 0; i < 5; i++)
	{

	}

	// 2.
	// 在C++ 中声明一个结构体变量不需要写再写(可以省略) struct 了，实际上把struct当成了一个类来处理（其实反过来说，应该是把类当成 结构体来使用了）
	student stu;
	stu.age = 24;

	std::cout << stu.age << std::endl;

	test();

	return 0;
}



// 在C++ 中不能 有 没有返回值的类型的 函数
// 因为C++是强类型
//f() { // 这是C语言可以的写法
//	return 10;
//}