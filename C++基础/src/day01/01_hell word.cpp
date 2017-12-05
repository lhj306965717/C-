
#include<iostream>

// 第三种使用方式
// using 是使用的意思
using namespace std;  // 命名空间，很类似java的中导包

int main_0(void)
{
	// cout 就是黑屏幕， endl 就是回车
	// 怎么看这句话呢？
	// 是将 字符串 流向 黑屏幕
	cout << "hello word" << endl;

	int a;

	// 将输入流向 a
	cin >> a;

	cout << "值：" << a << endl;

	return 0;
}


#if 0
{
	//第二种方式
	// 声明命名空间中的一个变量，用一个声明一个，并不是全部声明进来
	using std::cout;
	using std::cin;
	using std::endl;
}
#endif

#if 0
{
	// 第一种方式
	// 直接使用的类型，不声明命名空间
	std::cout << "你好！世界..." << std::endl;
}
#endif

// C语言写法
#if 0
{
#include<stdio.h>

int main()
{
	printf("hello word\n");

	return 0;
}
}
#endif
