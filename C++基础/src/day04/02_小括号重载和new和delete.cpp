#include<iostream>


using namespace std;

// ����С����

class Sqr
{
private:
	int a;

public:

	Sqr(int a)
	{
		this->a = a;
	}

	int operator()(int value)
	{
		return value * value;
	}
};



class A
{
private:
	int a;

public:
	// Ĭ�Ϲ��캯��
	A() 
	{
		cout << "�޲ι��캯��" << endl;
	}

	A(int a)
	{
		cout << "A�Ĺ��캯��" << endl;
		this->a = a;
	}

	// ע�⣺size_t ���� unsigned int
	// ���ص�new������ ��Ȼ�ᴥ������Ĺ��캯��
	void * operator new(size_t size)
	{
		// ����Ĵ�С��4��Ϊʲô�أ���Ϊ������е� ֻ��һ�� int ���͵ı���
		// ��������������������ô���size�Ĵ�С�Ͳ���4��
		cout << "������new������ : " << size << endl;
		return malloc(size);
	}

	// ���� delete
	void operator delete(void *p)
	{
		cout << "������ delete ������" << endl;
		free(p);
	}

	// ע�⣺�������ص� �� " new[] "
	void * operator new[](size_t size)
	{
		cout << "������ new [] ������ : " << size << endl;
		return malloc(size);
	}

	void operator delete[](void * p)
	{
		cout << "������ delete[] ������" << endl;
		free(p);
	}

	~A()
	{
		cout << "A ����������" << endl;
	}
};

int main_02(void)
{
	Sqr s(10);

	// ���ǽ�һ������ ����һ����ͨ����������
	// �����ֶ����Ƿº�������α����
	int a = s(2);// ע�⣺���ﲻ�ǵ��ù��캯�����ǵ���һ���޲εĺ���


	A *p = new A(10); // 10 �����������Ϊ�˴��� ���������Ĺ��캯��
	//p->operator new(sizeof(A)); // ʵ������������������

	delete p; // �ͷ�


	A *arr = new A[3];
	//arr->operator new[](sizeof(A) * 3); // ����ʵ�ʵĵ��÷�ʽ

	delete[] arr; // �ͷ�

	return 0;
}

// ע�⣺���Ƽ� ��д && || ����Ϊ��д�ˣ�����ʵ�ֶ�·���ܣ���&& �����һ������Ϊfalse����ô������������ǻ�ִ��(��·�����ǲ���ִ�е�)