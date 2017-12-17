#include<iostream>

using namespace std;

// 比较常用的 左移右移 操作符重载

class Complex
{
private:
	int a;
	int b;

public:
	Complex(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	void printfComplex()
	{
		cout << this->a << "  :  " << this->b << endl;
	}

	// 全局的友元形式
	friend ostream& operator<<(ostream &os, Complex &c);

	// 不建议 左移操作符 写在成员方法中，否则调用的顺序会变反
	ostream& operator<<(ostream &os)
	{
		os << "(" << this->a << " : " << this->b << ")";

		return os;
	}

	// 右移操作符
	friend istream& operator >> (istream &is, Complex &c);
};

// 左移 操作符重载
ostream& operator<<(ostream &os, Complex &c)
{
	os << "(" << c.a << " : " << c.b << ")";

	return os;
}

// 右移操作符重载
istream& operator>>(istream &is, Complex &c)
{
	is >> c.a >> c.b;

	return is;
}


class Array
{
private:
	int value;

public:
	Array(int value)
	{
		this->value = value;
	}

	Array()
	{}

	friend ostream& operator<<(ostream &os, Array &arr);
};

ostream& operator<<(ostream &os, Array &arr)
{
	os << arr.value;

	return os;
}

int main_08(void)
{
	
	Complex c1(1, 2);
	
	Complex c2(10, 20);

	cout << c1 << c2;

	cout << endl; // 分割线

	// 写成 成员方法函数 的调用方式
	c1 << cout; // 发现调用顺序反了，所以不建议将 左移 写在成员函数中


	cout << endl; // 分割线

	//  右移操作符的使用
	//cin >> c1 >> c2;

	//c1.printfComplex();
	//c2.printfComplex();



	// 测试直接识别数组：

	Array p1(1);
	Array p2(2);
	Array p3(3);

	Array pt[3] = {p1, p2, p3};

	cout << pt[0] << pt[1] << pt[2];

	cout << endl; // 分割线

	return 0;
}

