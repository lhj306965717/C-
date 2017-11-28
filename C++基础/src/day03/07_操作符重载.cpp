#include <iostream>

using namespace std;

class Complex
{

	// 声明 友元
	friend Complex complexAdd(Complex &c1, Complex &c2);

	// 声明 友元 操作符重载 
	//friend Complex operator+(Complex &c1, Complex &c2);

	friend Complex& operator-(Complex &c1, Complex &c2);

public:
	Complex(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	void printfComplex()
	{
		cout << this->a << "  :  " << this->b  <<endl;
	}

	// 成员 操作符重载
	// 在类中进行操作符重载函数的参数 只能有一个
	// 因为此操作符本身就在一个类中(即一个对象中), 所以只需要一个参数
	Complex operator+(Complex &another)
	{
		Complex temp(this->a+another.a, this->b+another.b);

		return temp;
	}

	// 声明操作符重载
	//Complex operator+(Complex &c);


	friend Complex& operator+=(Complex &c1, Complex &c2);

	// 写在类内部
	const Complex& operator-=(Complex &another)
	{
		this->a -= another.a;
		this->b -= another.b;

		return *this;
	}

	// 前++ 运算符(先++再使用)
	//friend Complex& operator++(Complex &another);

	// ++ 运算符重载 写在 函数内部
	Complex& operator++()
	{
		this->a++;
		this->b++;

		// 非常量引用的初始值，必须为左值
		// 即 

		return *this;  // 因为 this 是一个 指针
	}

	// 后 ++
	friend const Complex& operator++(Complex &c, int);

private:
	int a;
	int b;
};

// 通过声明的方式进行成员函数操作符重载
Complex operator+(Complex &c1, Complex &c2)
{
	cout << "成员操作符重载" << endl;

	return c1;
}

// 前++ 的运算符重载
//Complex& operator++(Complex &another)
//{
//	another.a++;
//	another.b++;
//
//	return another;
//}

// 后 ++
// 由于 重载运算符的规则是 一个对象和一个常规类型
// 占位没有任何的意义，在这里只是为了符合规则
const Complex& operator++(Complex &c, int) // 这里有一个占位符，这里使用了占位符
{
	Complex temp(c.a, c.b); // 保存一个临时值

	// 先使用 后增加 

	c.a++;
	c.b++;

	return temp;
}

Complex complexAdd(Complex &c1, Complex &c2)
{
	// 创建一个 Complex 对象
	Complex temp(c1.a + c2.a, c1.b + c2.b);

	return temp;
}

//  重载 & 操作符
int operator&(Complex c)
{
	//return &c; // 这里不能写 & 因为重载了操作符，会造成 重复调用 栈溢出
	return 0;
}

// 操作符重载写在全局
//Complex operator+(Complex &c1, Complex &c2)
//{
//	Complex temp(c1.a + c2.a, c1.b + c2.b);
//
//	return temp;
//}

Complex& operator-(Complex &c1, Complex &c2)
{
	Complex temp(c1.a-c2.a, c1.a-c2.b);

	return temp; // 可以返回临时 的 对象地址，因为 对象是不会消失的，消失的 temp 这个 局部变量
}


// 双目运算符重载
Complex& operator+=(Complex &c1, Complex &c2)
{
	c1.a += c2.a;
	c1.b += c2.b;

	return c1;
}

int main_07(void)
{

	Complex c1(1, 2);
	Complex c2(2, 4);

	// 通过全局函数的方式相加
	//Complex temp = complexAdd(c1, c2);
	//temp.printfComplex();

	// 通过操作符重载的方式进行相加
	//Complex temp = c1 + c2;
	//temp.printfComplex();

	Complex temp1 = c2 - c1;
	temp1.printfComplex();

	// 调用局部的运算符重载
	Complex temp2 = c1.operator+(c2);
	temp2.printfComplex();

	int address = operator&(c2);
	printf("0x%d\n", address);



	// 前++ 运算符的使用
	(++c1).printfComplex();;

	return 0;
}


// 重载运算符规则总结：
// 1.C++不允许用户自己定义新的运算符，只能对已有的C++运算符重载
// 2.C++允许重载的运算符
// 3.重载不能改变运算符运算对象（即操作数）的个数
// 4.重载不能改变运算符的优先级
// 5.重载不能改变运算符的结合性
// 6.重载运算符的函数不能有默认的参数(否则就改变了运算参数的个数，与前面第3点矛盾)
// 7.重载的运算符必须和用户的自定义类型的对象一起使用，其参数至少应有一个是类对象(或者类对象引用)
// 8.用于类对象的运算符一般必须重载，但有两个例外，运算符 "=" 和 "&" 不必用户重载
// 9.应当使重载运算符的功能类似改运算符作用于标准类型数据时所实现的功能。
// 10.运算符重载函数可以是类的成员函数，也可以是类的友元函数，不可以是既非类的成员函数也不是友元函数的普通函数