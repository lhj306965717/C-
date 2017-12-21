#include<iostream>

using namespace std;

class Person
{
public:
	int m;

	Person(int m)
	{
		this->m = m;
	}

	Person()
	{

	}

	void printf()
	{
		cout << "m: " << m << endl;
	}
};

// 声明 Man 类 是 虚继承
// 虚继承的作用是为了 我的儿子多继承中出现不明确的现象，出现歧义
class Man : virtual public Person
{
public:
	Man(int m)
	{
		this->m = m;
	}

	Man() {}
};

// 都要声明 virtual
class WoMan : virtual public Person
{
public:
	WoMan(int m)
	{
		this->m = m;
	}

	WoMan() {}
};

// 如果出现菱形的继承关系

// 雌雄同体
class Androgynous : public Man, WoMan
{
public:
	Androgynous(int m)
	{
		//this->Man::m = m; // 会提示不明确 m 属性
		// 此时 如果创建一个对象，会有两个m，因为从两个父类中都把m属性
		// 继承过来了

		// 如果 Man, WoMan 都声明了是 虚继承，此时就不会出现属性歧义
		this->m = m;
	}
};


int main_06(void)
{
	Person *p1 = new Man(10);
	p1->printf();

	Person *p2 = new WoMan(100);
	p2->printf();

	Androgynous *a = new Androgynous(10);
	a->printf();

	return 0;
}