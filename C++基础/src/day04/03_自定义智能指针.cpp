#include <iostream>

#include <memory>

using namespace std;

class B
{
private:
	int a;
public:
	B(int a)
	{
		this->a = a;
	}

	void func()
	{
		cout << "���� func ����" << endl;
	}

	~B()
	{
		cout << "����B" << endl;
	}
};

class MyAutoPtr
{
private:
	B *ptr;
public:
	MyAutoPtr(B *ptr)
	{
		this->ptr = ptr;
	}

	~MyAutoPtr()
	{
		if (this->ptr != NULL)
		{
			delete this->ptr;
			this->ptr = NULL;
			this->ptr = nullptr; // �������Ч����һ����
		}

		cout << "�������� MyAutoPtr" << endl;
	}

	// ��д -> ������
	B * operator ->()
	{
		return this->ptr;
	}

	// ��д * ������
	B & operator *()
	{
		return *this->ptr;
	}
};

int main_03(void)
{
	//int *p = new int;
	//// �������һ���������ͣ���һ��ָ��int���͵�ָ��
	//auto_ptr<int> ptr(new int);

	//*ptr = 20;

	//B *pa = new B(10);
	//pa->func(); // ��ʵ �࣬���� һ���ṹ��
	//delete pa;


	//auto_ptr<B> ptra(new B(100));
	//ptra->func();
	////  ����Ҫ�ֶ��ͷ�


	cout << "++++++++++++++++++++++++++++++++" << endl;

	// ��� ������������룬��ӡ�����Ľ�����и���

	MyAutoPtr myPtr(new B(1000));
	myPtr->func();

	(*myPtr).func();

	return 0;
}