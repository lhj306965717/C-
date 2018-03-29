#include<iostream>

using namespace std;

class Parent
{
public:
	virtual void func() {
		cout << "Parent::func()..." << endl;
	}

private:
	int a;
};

class Parent2
{
	void func() {
		cout << "Parent2::func()..." << endl;
	}

private:
	int a;
};

int main_02(void)
{
	Parent p1;

	cout << "Parent大小：" << sizeof(p1) << endl;

	Parent2 p2;

	cout << "Parent2大小：" << sizeof(p2) << endl;

	// 通过打印结果发现： 第一个是8个字节，第二个是4个字节，恰好说明存在存在一个指针的大小，即vptr

	return 0;
}