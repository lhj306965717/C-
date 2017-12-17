#include<iostream>

using namespace std;

class Parent
{
	int def; // 默认的方式，在当前类的内部可以访问，在继承类的内部不可以访问

public:
	int pub; // 在类的内部 和 外部可以访问

protected:
	int pro; // 在类的内部可以访问，在类的外部不可以访问

private:
	int pri; // 在类的内部可以访问，在类的外部不可以访问
};


// 类的继承方式：为保护继承
class Child : protected Parent
{
public:
	void f()
	{
		cout << pro << endl;
	}
};

// 总结：跟 JAVA 的继承方式非常相似

int main_02(void)
{

	Child * child = new Child;

	// 如果继承的性质是公有，那么就可以访问，如果是其他，则外部不能访问
	//cout << child->pub << endl; // 可以访问

	return 0;
}