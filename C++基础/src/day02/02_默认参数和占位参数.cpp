#include <iostream>

using namespace std;

// 传递参数就是传递的参数，没传就是 默认参数
void func(int i = 10) {
	cout << i << endl;
}

// 总结：凡是写了占位参数的右边都需要要写占位参数

// 不能只有一个默认参数，有一个，全部都必须要有
// 但是有一个条件是：如果最左边的形参有占位参数，那么其他都必须要有。
void func1(int a, int b, int c = 100) {
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}


// 为什么呢？假如一个函数有两个参数，最右边的参数有默认值，此时调用这个函数只传递一个参数，那么最右边的参数就没有值了(注意：赋值是从左到右的赋值)，
// 所以默认的参数的右边一定要有默认参数

/*占位参数*/
// 第二个参数只是起到占位的作用
void func2(int a, int) {
	cout << "a=" << a << endl;
}

int main_02(void) {

	func();

	func1(10, 11); // 没有写占位参数的，就必须要传占位参数

	func2(111, 0);

	return 0;
}