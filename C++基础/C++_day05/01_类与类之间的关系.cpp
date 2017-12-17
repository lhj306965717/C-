#include<iostream>


using namespace std;


class A
{

};


// 类B拥有类A的成员变量，B has A  即 B依赖A
class B
{
public:
	A a; 

	B(A a):a(a)
	{

	}
};

// 类C的成员方法需要类B的形参，C use B
class C
{
public:
	void func(B b)
	{

	}
};

class D : public C 
{
	// 注意：这里继承 C 有两种写法：
	// (1) 直接class D : C ，但是不能通过 D 来调用 C 的成员，包括公有，
	// (2) class D : public C , 这样就可以 通过 D 来调用 C 中的成员
};

class E : D
{
protected:
	D d;
	C c;
public:
	E(D d, C c) : d(d), c(c)
	{
	}
};

class F : E
{
private:
	int id;
public:
	F(int id, A a) : E(d, c)
	{
		// 这里为什么this 只能是使用 -> 这个呢？
		// 是因为 this 他是一个 指针
		this->id = id;
	}
};

int main_01(void)
{
    A* a = new A;
	B* b = new B(*a);

	D* d = new D;
	d->func(*b);

	//E* e = new E;
	//e->func(*b);

	return 0;
}