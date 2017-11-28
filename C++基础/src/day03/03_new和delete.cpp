#include <iostream>

using namespace std;

// 特别总结：
int a(10); // 这样声明也是可以的，实际上是 int a = 10; 声明后就直接初始化


class Test
{
public:
	Test(int a, int b)
	{
		this->m_a;
		this->m_b;

		cout << "Test 构造函数" << endl;
	}

	~Test()
	{
		cout << "Test 析构" << endl;
	}

	void printf()
	{
		cout << m_a << " : " << m_b << endl;
	}

private:
	int m_a;
	int m_b;
};


// C语言中
static void test()
{
	int *p = (int *)malloc(sizeof(int));

	*p = 10;

	if (p != NULL)
	{
		//free(p);

		delete p; // malloc出来的空间，一样可以用delete释放

		p = NULL;
	}

	// 创建数组
	int *array_p = (int *)malloc(sizeof(int) * 10);

	for (int i = 0; i < 10; i++)
	{
		array_p[i] = i + 1;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << "i = " << array_p[i] << endl;
	}

	if (array_p != NULL)
	{
		free(array_p);
		array_p = NULL;
	}


	cout << "*****************************************" << endl;

	Test *tp = (Test *)malloc(sizeof(Test));

	// 没法使用构造函数进行初始化

	(*tp).printf();
	// tp->printf();

	if (tp != NULL)
	{
		free(tp);
	}
}

// 区别：
// malloc free 是函数， 标准库 stdio.h
// C++ 中是 new  delete是关键字

// C++ 语法
static void test1()
{
	int *p = new int;
	*p = 10;

	cout << *p << endl;

	//delete p;

	free(p); // new 的空间也一样可以被 free释放

	p = NULL;

	//-------------------------------

	// 注意： int *array_p = new int(10); // 声明数组不能这样写，后面只能是中括号
	// 这样写，相当于分配空间后就直接初始化了
	int *array_p = new int[10]; // 声明一个数组 10个元素 int

	for (int i = 0; i < 10; i++)
	{
		array_p[i] = i + 1;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << array_p[i] << ", " << endl;
	}

	if (array_p != NULL)
	{
		delete[] array_p; // 注意释放数组
		array_p = NULL;
	}

	cout << "********************** C++ *******************" << endl;

	// 初始化是通过构造函数进行初始化的
	Test *tp = new Test(10, 100); // 通过分配空间就初始化
	// 没有参数，就是触发无参构造

	// 区别：new 会出发 对象的构造函数，malloc就不行

	tp->printf();

	if (tp != NULL)
	{
		delete tp; // 会触发对象的析构函数
		tp = NULL;
	}
}




int main_03(void)
{
	test1();

	return 0;
}