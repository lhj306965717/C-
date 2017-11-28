#include<iostream>

using namespace std;

// �Ƚϳ��õ� �������� ����������

class Complex
{
private:
	int a;
	int b;

public:
	Complex(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	void printfComplex()
	{
		cout << this->a << "  :  " << this->b << endl;
	}

	// ȫ�ֵ���Ԫ��ʽ
	friend ostream& operator<<(ostream &os, Complex &c);

	// ������ ���Ʋ����� д�ڳ�Ա�����У�������õ�˳���䷴
	ostream& operator<<(ostream &os)
	{
		os << "(" << this->a << " : " << this->b << ")";

		return os;
	}

	// ���Ʋ�����
	friend istream& operator >> (istream &is, Complex &c);
};

// ���� ����������
ostream& operator<<(ostream &os, Complex &c)
{
	os << "(" << c.a << " : " << c.b << ")";

	return os;
}

// ���Ʋ���������
istream& operator>>(istream &is, Complex &c)
{
	is >> c.a >> c.b;

	return is;
}


class Array
{
private:
	int value;

public:
	Array(int value)
	{
		this->value = value;
	}

	Array()
	{}

	friend ostream& operator<<(ostream &os, Array &arr);
};

ostream& operator<<(ostream &os, Array &arr)
{
	os << arr.value;

	return os;
}

int main_08(void)
{
	
	Complex c1(1, 2);
	
	Complex c2(10, 20);

	cout << c1 << c2;

	cout << endl; // �ָ���

	// д�� ��Ա�������� �ĵ��÷�ʽ
	c1 << cout; // ���ֵ���˳���ˣ����Բ����齫 ���� д�ڳ�Ա������


	cout << endl; // �ָ���

	//  ���Ʋ�������ʹ��
	//cin >> c1 >> c2;

	//c1.printfComplex();
	//c2.printfComplex();



	// ����ֱ��ʶ�����飺

	Array p1(1);
	Array p2(2);
	Array p3(3);

	Array pt[3] = {p1, p2, p3};

	cout << pt[0] << pt[1] << pt[2];

	cout << endl; // �ָ���

	return 0;
}

