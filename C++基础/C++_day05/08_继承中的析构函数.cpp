#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>

using namespace std;

class A
{
private:
	char *p;
public:
	A()
	{
		cout << "����A�Ĺ���" << endl;
		this->p = new char[20];
		memset(this->p, 0, 20);
		strcpy(this->p, "A String...");
	}

	// �����ּ̳е�ʱ�������Ҫͬʱ�����鹹�ͷ� ���������
	// ��ô���� ���� ������������ ���� virtual����Ϊ�麯���Ϳ�����
	virtual ~A() 
	{
		cout << "����A������" << endl;

		if (this->p != NULL)
		{
			delete[] this->p;
			this->p = NULL;
		}
	}

	void pintf()
	{
		cout << this->p << endl;
	}
};

class B : public A
{
private:
	char *p;
public:
	B()
	{
		cout << "����B�Ĺ���" << endl;
		this->p = new char[20];
		memset(this->p, 0, 20);
		strcpy(this->p, "B String...");
	}

	~B()
	{
		cout << "����B������" << endl;

		if (this->p != NULL)
		{
			delete[] this->p;
			this->p = NULL;
		}
	}
};

void func(A *ap)
{
	ap->pintf(); // Ĭ�ϻ���� A �еķ���

	delete ap;
}

int main(void)
{

	B *b = new B;

	func(b);

	return 0;
}  