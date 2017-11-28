#include <iostream>

using namespace std;

// �ر��ܽ᣺
int a(10); // ��������Ҳ�ǿ��Եģ�ʵ������ int a = 10; �������ֱ�ӳ�ʼ��


class Test
{
public:
	Test(int a, int b)
	{
		this->m_a;
		this->m_b;

		cout << "Test ���캯��" << endl;
	}

	~Test()
	{
		cout << "Test ����" << endl;
	}

	void printf()
	{
		cout << m_a << " : " << m_b << endl;
	}

private:
	int m_a;
	int m_b;
};


// C������
static void test()
{
	int *p = (int *)malloc(sizeof(int));

	*p = 10;

	if (p != NULL)
	{
		//free(p);

		delete p; // malloc�����Ŀռ䣬һ��������delete�ͷ�

		p = NULL;
	}

	// ��������
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

	// û��ʹ�ù��캯�����г�ʼ��

	(*tp).printf();
	// tp->printf();

	if (tp != NULL)
	{
		free(tp);
	}
}

// ����
// malloc free �Ǻ����� ��׼�� stdio.h
// C++ ���� new  delete�ǹؼ���

// C++ �﷨
static void test1()
{
	int *p = new int;
	*p = 10;

	cout << *p << endl;

	//delete p;

	free(p); // new �Ŀռ�Ҳһ�����Ա� free�ͷ�

	p = NULL;

	//-------------------------------

	// ע�⣺ int *array_p = new int(10); // �������鲻������д������ֻ����������
	// ����д���൱�ڷ���ռ���ֱ�ӳ�ʼ����
	int *array_p = new int[10]; // ����һ������ 10��Ԫ�� int

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
		delete[] array_p; // ע���ͷ�����
		array_p = NULL;
	}

	cout << "********************** C++ *******************" << endl;

	// ��ʼ����ͨ�����캯�����г�ʼ����
	Test *tp = new Test(10, 100); // ͨ������ռ�ͳ�ʼ��
	// û�в��������Ǵ����޲ι���

	// ����new ����� ����Ĺ��캯����malloc�Ͳ���

	tp->printf();

	if (tp != NULL)
	{
		delete tp; // �ᴥ���������������
		tp = NULL;
	}
}




int main_03(void)
{
	test1();

	return 0;
}