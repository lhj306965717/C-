#include<iostream>

using namespace std;

// 都在末尾添加了s, 否则会出现 跟 06_多继承与虚继承中出现冲突
class Persons
{
public:

	// 此时这个virtual代表的意义又不一样了
	// 使用 virtual 声明的函数被重写后即可展现多态特性
	virtual void fperson()
	{
		cout << "Person方法执行..." << endl;
	}
};

// 声明 Man 类 是 虚继承
// 虚继承的作用是为了 我的儿子多继承中出现不明确的现象，出现歧义
class Mans : public Persons
{
public:
	void fperson()
	{
		cout << "Man方法执行..." << endl;
	}
};

// 都要声明 virtual
class WoMans : public Persons
{
public:
	void fperson()
	{
		cout << "WoMan方法执行..." << endl;
	}
};

// 现在提供一个全局的方法来调用方法
void f(Persons *p)
{
	p->fperson();
	// 希望展现多态的特性，
	// 传递的是 父类就调用父类的方法
	// 传递的是 子类就调用子类的方法
}

int main_07(void)
{
	Persons *p = new Persons;
	//p->fperson();

	f(p); //结果：调用Person类的 fperson() 方法

	Mans *m = new Mans;
	//m->fperson();

	f(m); // 此时通过全局的公用方法用指针区调用，
	// 发现，都是调用的 Person 类的 fperson() 方法

	WoMans *wm = new WoMans;
	//wm->fperson();
	
	f(wm); // 结果： 调用的 Person 类的 fperson() 方法


	// 多态发生的三个必要条件：
	// 1.要有继承
	// 2.要有虚函数重写，必须函数前面声明了virtual（只有声明了virtual的才是虚函数重写）
	// 3.父类指针或者引用指向子类对象


	//delete p;
	//delete m;
	//delete wm;

	return 0;
}