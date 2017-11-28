#include <iostream>

using namespace std;

struct student
{
private:
	int a;
    int b;

	// 构造函数
public:student(int a, int b)
{
	this->a = a;
	this->b = b;
}
};

// 声明静态，防止多个文件中的声明出现重复
class Test
{
public:
	Test(int x, int y) // 构造函数
	{
		this->m_x = x;
		this->m_y = y;

		cout << "有参构造函数被调用" << endl;
	}

	// 跟java一样，一旦定义了一个构造函数，那么默认的构造函数就不能使用了，
	// 只能手动创建一个默认的构造函数
	Test() {
		cout << "无参构造函数被调用" << endl;
	}

	int getMX() {
		return m_x;
	}

	int getMY() {
		return m_y;
	}

private:
	int m_x;  // 注意：类中全局变量是不会自动初始化的，跟java有区别
	int m_y;

	// 析构函数
public:
	void printf() {	
		cout << "m_x=" << this->m_x << "  m_y=" << this->m_y << endl;
	}

	~Test() 
	{
		cout << "析构函数被调用" << endl;

		// 析构函数是在这个对象 临死之前，要自动调用析构函数
		// 在被对象销毁之前调用

		// 作用：内存释放
	}


	// 注意：每个类 如果不显示的提供构造函数和析构函数，都会存在默认的无参构造函数
	// 如果显示的提供了构造函数，那么都会覆盖掉默认的


	// 拷贝构造函数：使用本身类型的一个对象通过构造函数来初始化自己
	Test(const Test & another) {
		this->m_y = another.m_y;
		this->m_x = another.m_x;

		cout << "调用拷贝构造函数" << endl;
	}

	// 默认就上面提供的拷贝构造函数
	// 注意：会提供一个默认的 拷贝构造函数，就单纯的将另一个的数据，全部赋值

	// 重要注意：当一个方法返回一个对象时，会发生调用拷贝构造，因为 返回值会赋值给 匿名对象(其实是因为函数返回的副本机制导致)


	// 总结：

	// 类中会有个默认的无参构造函数：
	// 1.当没有任何显示的构造函数（显示的无参，显示的有参，显示拷贝构造函数），默认的无参够咱函数就会被调用


	// 操作符重载
	void operator=(const Test& another)
	{
		cout << "operator=(const Test& another)" << endl;
	}
};

// 为什么这里会产生值拷贝？是因为函数的副本机制导致
void func(Test t) // 这里是 Test t = t1; // 是值拷贝，此时是拷贝构造函数
{
	cout << "func begin...." << endl;

	t.printf();

	cout << "func end....." << endl;
}

Test func1(Test t) {

	cout << "func1 begin...." << endl;

	Test t1(t);

	t1.printf();

	cout << "func1 end....." << endl;

	return t1;
}

Test fun2()
{
	cout << "func2 begin...." << endl;

	Test t1(5, 10);

	t1.printf();

	//Test t2 = t1;
	// 被注释掉的这两种调用方式是不一样的，第一种会直接调用拷贝构造函数
	// 第二种，会直接调用 =操作符重载
	//Test t2;
	//t2 = t1;

	cout << "func2 end....." << endl;

	return t1;
}

// 测试 各种函数的调用顺序
static void test1() {
	Test t1(10, 20);
	Test t2;

	t2 = t1;
}

static void test2()
{
	cout << "test2 begin...." << endl;

	Test t1(10, 100);

	func(t1);

	cout << "test2 end....." << endl;
}

static void test3()
{
	cout << "test3 begin...." << endl;

	Test t1(5, 10);

	// 这里返回给t2其实是值拷贝，所以会调用拷贝构造函数
	//Test t2 = func1(t1);
	//t2.printf

	t1 = func1(t1);

	t1.printf();

	cout << "test3 end....." << endl;
}

static void test4()
{
	Test t1(10, 50);

	printf("%p\n", &t1);

	Test t2(20, 30);

	printf("%p\n", &t2);

	t2 = t1; // =操作符，这里会调用 t2的操作符重载

	printf("%p\n", &t2);

	t2.printf();

	Test t3 = t2; // 调用拷贝构造函数
}

static void test5()
{
	Test t;

	t = fun2();

	cout << "*****************************" << endl;

	Test t1 = fun2(); // 这里只是值拷贝了，并没有 出现 操作符的调用

	t1.printf();
}

// 总结：构造与析构函数的调用相反，谁先构造，谁先析构
// 总结：只要涉及到 函数的 参数 是对象的，不管是 形参 还是返回值，那么都会进行一次 拷贝构造函数的操作，这是因为函数的副本机制导致的

int main_01(void) {

	//Test t(10, 100);

	//cout << t.getMX() << endl;

	//Test tt;

	//cout << tt.getMX() << " : " << tt.getMY() << endl;


	//--------   测试代码   ------------

	//test1();

	//test2();

	//test3();

	//test4();

	test5();


	return 0;
}