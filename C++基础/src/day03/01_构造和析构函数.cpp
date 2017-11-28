#include <iostream>

using namespace std;

struct student
{
private:
	int a;
    int b;

	// ���캯��
public:student(int a, int b)
{
	this->a = a;
	this->b = b;
}
};

// ������̬����ֹ����ļ��е����������ظ�
class Test
{
public:
	Test(int x, int y) // ���캯��
	{
		this->m_x = x;
		this->m_y = y;

		cout << "�вι��캯��������" << endl;
	}

	// ��javaһ����һ��������һ�����캯������ôĬ�ϵĹ��캯���Ͳ���ʹ���ˣ�
	// ֻ���ֶ�����һ��Ĭ�ϵĹ��캯��
	Test() {
		cout << "�޲ι��캯��������" << endl;
	}

	int getMX() {
		return m_x;
	}

	int getMY() {
		return m_y;
	}

private:
	int m_x;  // ע�⣺����ȫ�ֱ����ǲ����Զ���ʼ���ģ���java������
	int m_y;

	// ��������
public:
	void printf() {	
		cout << "m_x=" << this->m_x << "  m_y=" << this->m_y << endl;
	}

	~Test() 
	{
		cout << "��������������" << endl;

		// ������������������� ����֮ǰ��Ҫ�Զ�������������
		// �ڱ���������֮ǰ����

		// ���ã��ڴ��ͷ�
	}


	// ע�⣺ÿ���� �������ʾ���ṩ���캯���������������������Ĭ�ϵ��޲ι��캯��
	// �����ʾ���ṩ�˹��캯������ô���Ḳ�ǵ�Ĭ�ϵ�


	// �������캯����ʹ�ñ������͵�һ������ͨ�����캯������ʼ���Լ�
	Test(const Test & another) {
		this->m_y = another.m_y;
		this->m_x = another.m_x;

		cout << "���ÿ������캯��" << endl;
	}

	// Ĭ�Ͼ������ṩ�Ŀ������캯��
	// ע�⣺���ṩһ��Ĭ�ϵ� �������캯�����͵����Ľ���һ�������ݣ�ȫ����ֵ

	// ��Ҫע�⣺��һ����������һ������ʱ���ᷢ�����ÿ������죬��Ϊ ����ֵ�ḳֵ�� ��������(��ʵ����Ϊ�������صĸ������Ƶ���)


	// �ܽ᣺

	// ���л��и�Ĭ�ϵ��޲ι��캯����
	// 1.��û���κ���ʾ�Ĺ��캯������ʾ���޲Σ���ʾ���вΣ���ʾ�������캯������Ĭ�ϵ��޲ι��ۺ����ͻᱻ����


	// ����������
	void operator=(const Test& another)
	{
		cout << "operator=(const Test& another)" << endl;
	}
};

// Ϊʲô��������ֵ����������Ϊ�����ĸ������Ƶ���
void func(Test t) // ������ Test t = t1; // ��ֵ��������ʱ�ǿ������캯��
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
	// ��ע�͵��������ֵ��÷�ʽ�ǲ�һ���ģ���һ�ֻ�ֱ�ӵ��ÿ������캯��
	// �ڶ��֣���ֱ�ӵ��� =����������
	//Test t2;
	//t2 = t1;

	cout << "func2 end....." << endl;

	return t1;
}

// ���� ���ֺ����ĵ���˳��
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

	// ���ﷵ�ظ�t2��ʵ��ֵ���������Ի���ÿ������캯��
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

	t2 = t1; // =���������������� t2�Ĳ���������

	printf("%p\n", &t2);

	t2.printf();

	Test t3 = t2; // ���ÿ������캯��
}

static void test5()
{
	Test t;

	t = fun2();

	cout << "*****************************" << endl;

	Test t1 = fun2(); // ����ֻ��ֵ�����ˣ���û�� ���� �������ĵ���

	t1.printf();
}

// �ܽ᣺���������������ĵ����෴��˭�ȹ��죬˭������
// �ܽ᣺ֻҪ�漰�� ������ ���� �Ƕ���ģ������� �β� ���Ƿ���ֵ����ô�������һ�� �������캯���Ĳ�����������Ϊ�����ĸ������Ƶ��µ�

int main_01(void) {

	//Test t(10, 100);

	//cout << t.getMX() << endl;

	//Test tt;

	//cout << tt.getMX() << " : " << tt.getMY() << endl;


	//--------   ���Դ���   ------------

	//test1();

	//test2();

	//test3();

	//test4();

	test5();


	return 0;
}