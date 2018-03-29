#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>

using namespace std;

class A
{
private:
	char *p;
public:
	A()
	{
		cout << "触发A的构造" << endl;
		this->p = new char[20];
		memset(this->p, 0, 20);
		strcpy(this->p, "A String...");
	}

	// 当出现继承的时候，如果需要同时进行虚构释放 父类和子类
	// 那么就在 父类 的析构函数上 加上 virtual，改为虚函数就可以了
	virtual ~A() 
	{
		cout << "触发A的析构" << endl;

		if (this->p != NULL)
		{
			delete[] this->p;
			this->p = NULL;
		}
	}

	void pintf()
	{
		cout << this->p << endl;
	}
};

class B : public A
{
private:
	char *p;
public:
	B()
	{
		cout << "触发B的构造" << endl;
		this->p = new char[20];
		memset(this->p, 0, 20);
		strcpy(this->p, "B String...");
	}

	~B()
	{
		cout << "触发B的析构" << endl;

		if (this->p != NULL)
		{
			delete[] this->p;
			this->p = NULL;
		}
	}
};

void func(A *ap)
{
	ap->pintf(); // 默认会调用 A 中的方法

	delete ap;
}

int main(void)
{

	B *b = new B;

	func(b);

	return 0;
}  