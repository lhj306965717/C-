#include <stdio.h>
#include <stdlib.h>

#if 1  // 注意：预处理 在最外层不能使用括号包裹起来，

void fff() {
	printf("fff 方法被调用\n");
}

void ggg() {
	printf("ggg 方法被调用\n");
}

#endif
void ff() {
	printf("ff 方法被调用\n");
}


int main_(void) {

#if 1  // 预处理在里面可以 使用括号 包裹
	{
		fff();
		ggg();
	}
	#endif

	return 0;
}
