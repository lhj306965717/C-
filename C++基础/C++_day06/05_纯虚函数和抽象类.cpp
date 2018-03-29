#include<iostream>

using namespace std;


// 图形类
class Shape
{
public:
	// 一个求图形面积的方法
	// 表示图形类声明一个方法getArea()， 他是一个纯虚函数，没有函数实现
	virtual double getArea() = 0; // 等于0 这种写法是 语法要求
};

// 总结：

// 1. 如果说一个类，拥有一个纯虚函数，就称这个类是一个抽象类
//    不管这个类中有没有成员属性，只要这个类有纯虚函数，就是一个抽象类，抽象类就是不能够实例化的(即不能创建抽象类的对象)

// 2. 如果说一个普通类，继承拥有纯虚函数的类，必须要重写这个虚函数。
//    如果不重写纯虚函数，依然是一个抽象类，且不能被实例化，
//    如果想实例化，必须要重写这个父类中所有纯虚函数

// 跟java中的 抽象类 一样，

// 矩形的面积(正方形)
class Rect : public Shape
{
private:
	int side;
public:
	Rect(int side)
	{
		this->side = side;
	}

	virtual double getArea()
	{
		return side*side;
	}
};

// 圆的面积
class Circle : public Shape
{
private:
	int r;
public:
	Circle(int r)
	{
		this->r = r;
	}
	virtual double getArea()
	{
		return 3.14*r*r;
	}
};

int main_05(void)
{
	// 
	Shape *sp1 = new Rect(10);
	double s1 = sp1->getArea();
	cout << "正方形面积=" << s1 << endl;

	Shape *sp2 = new Circle(4);
	double s2 = sp2->getArea();
	cout << "圆面积=" << s2 << endl;

	return 0;
}