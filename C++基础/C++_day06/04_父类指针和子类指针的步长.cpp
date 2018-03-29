#include<iostream>

using namespace std;

class Parent_p
{
public:
	Parent_p(int a)
	{
		this->a = a;
	}

	virtual void print() {
		cout << "Parent :: print  a=" << this->a << endl;
	}

private:
	int a;
};

class Child_c : public Parent_p
{
public:
	Child_c(int a) : Parent_p(a)
	{
		this->b = a;
	}

	virtual void print() {
		cout << "Child :: print  b=" << this->b << endl;
	}

private:
	int b;
};

int main_04(void)
{

	Child_c arr[3] = { Child_c(1), Child_c(2), Child_c(4) };

	Parent_p *pp = &arr[0];
	Child_c *cp = &arr[0];

	pp->print();
	cp->print();

	pp++;
	cp++;

	cp->print();
	pp->print(); // 发现执行一句代码后报错


	// 父类指针 与 子类指针 步长 总结：

	// 由于指针的移动是根据类型的大小来移动的，所以，当子类对象被父类指针锁引用的时候
	// 此时这个父类指针移动的位置，是父类大小的位置，并不是子类大小的位置，所以会出现错误

	// 所以 对象指针移动的时候，不能使用多态，否则会出错(也有可能不会出错，但是实际这种是错误的)
	// （注意：如果子类与父类的大小一样，可以就会出现移动是正常的情况）

	return 0;
}