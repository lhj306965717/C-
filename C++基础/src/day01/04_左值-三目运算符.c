

#include <stdio.h>
#include <stdlib.h>



// 注意：这里最好用变量，如果直接使用 1 会报错

int aa = 1;

void test001() {

	int a = 10;
	int b = 20;
	int c = 1;

	// 左值(能放在赋值号左边的值叫左值)  右值（能放在赋值号右边的值叫右值）

	c = a < b ? a : b;

	//	(a < b ? a : b) = 50; // 在C语言中，报错,因为左边是一个数值

	// 修改为：
	*(a < b ? &a : &b) = 50; // 左边是 a 或者 b的地址，可以为地址赋值

	printf("value=%d\n", a);
}

int main_04c(void)
{

#if 1 
	{
		test001();
	}
#endif

	printf("执行...\n");

	return 0;
}
