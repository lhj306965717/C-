#include<iostream>

using namespace std;


// 为了避免跟以前的代码有冲突，所以添加 _s
class Parent_s
{
public:
	Parent_s(int a)
	{
		cout << "Parent(int a)" << endl;
		this->a = a;

		print();
	}

	virtual void print()
	{
		cout << "Parent :: void print()...  a=" << this->a << endl;
	}

private:
	int a;
};


class Child_s : public Parent_s
{
public:
	// 表示 参数 b 是 Child的构造参数
	Child_s(int a, int b) : Parent_s(b)//在调用父类构造器的时候，会将vptr指针当作父类来处理
	{
		cout << "Child(int a, int b)..." << endl;
		this->a = a;
		this->b = b;
	}

	// 问题：为什么在父类的构造函数中调用的print方法是 调用的父类中的
	// 因为在构造子类的时候会先构造父类(子类中会包含父类的内存空间)，此时构造的父类，
	// 那么此时的vptr指针会临时指向父类的虚函数表，且子类还没有被构造出来，所以调用的是父类的方法
	// 当构造完成后，构造子类的时候，此时vptr指针才会重新指向子类的虚函数表的入口地址，
	// 所以vptr指针初始化是从父类的表指向子类的表

	virtual void print()
	{
		cout << "Child :: void print()...  b=" << this->b << endl;

	}

private:
	int a;
	int b;
};

int main_03(void)
{
	Parent_s *p = new Child_s(1, 2);
	
	p->print(); // 此时调用的是子类的print函数

	delete p;

	return 0;
}