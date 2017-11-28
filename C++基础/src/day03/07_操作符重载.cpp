#include <iostream>

using namespace std;

class Complex
{

	// ���� ��Ԫ
	friend Complex complexAdd(Complex &c1, Complex &c2);

	// ���� ��Ԫ ���������� 
	//friend Complex operator+(Complex &c1, Complex &c2);

	friend Complex& operator-(Complex &c1, Complex &c2);

public:
	Complex(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	void printfComplex()
	{
		cout << this->a << "  :  " << this->b  <<endl;
	}

	// ��Ա ����������
	// �����н��в��������غ����Ĳ��� ֻ����һ��
	// ��Ϊ�˲������������һ������(��һ��������), ����ֻ��Ҫһ������
	Complex operator+(Complex &another)
	{
		Complex temp(this->a+another.a, this->b+another.b);

		return temp;
	}

	// ��������������
	//Complex operator+(Complex &c);


	friend Complex& operator+=(Complex &c1, Complex &c2);

	// д�����ڲ�
	const Complex& operator-=(Complex &another)
	{
		this->a -= another.a;
		this->b -= another.b;

		return *this;
	}

	// ǰ++ �����(��++��ʹ��)
	//friend Complex& operator++(Complex &another);

	// ++ ��������� д�� �����ڲ�
	Complex& operator++()
	{
		this->a++;
		this->b++;

		// �ǳ������õĳ�ʼֵ������Ϊ��ֵ
		// �� 

		return *this;  // ��Ϊ this ��һ�� ָ��
	}

	// �� ++
	friend const Complex& operator++(Complex &c, int);

private:
	int a;
	int b;
};

// ͨ�������ķ�ʽ���г�Ա��������������
Complex operator+(Complex &c1, Complex &c2)
{
	cout << "��Ա����������" << endl;

	return c1;
}

// ǰ++ �����������
//Complex& operator++(Complex &another)
//{
//	another.a++;
//	another.b++;
//
//	return another;
//}

// �� ++
// ���� ����������Ĺ����� һ�������һ����������
// ռλû���κε����壬������ֻ��Ϊ�˷��Ϲ���
const Complex& operator++(Complex &c, int) // ������һ��ռλ��������ʹ����ռλ��
{
	Complex temp(c.a, c.b); // ����һ����ʱֵ

	// ��ʹ�� ������ 

	c.a++;
	c.b++;

	return temp;
}

Complex complexAdd(Complex &c1, Complex &c2)
{
	// ����һ�� Complex ����
	Complex temp(c1.a + c2.a, c1.b + c2.b);

	return temp;
}

//  ���� & ������
int operator&(Complex c)
{
	//return &c; // ���ﲻ��д & ��Ϊ�����˲������������ �ظ����� ջ���
	return 0;
}

// ����������д��ȫ��
//Complex operator+(Complex &c1, Complex &c2)
//{
//	Complex temp(c1.a + c2.a, c1.b + c2.b);
//
//	return temp;
//}

Complex& operator-(Complex &c1, Complex &c2)
{
	Complex temp(c1.a-c2.a, c1.a-c2.b);

	return temp; // ���Է�����ʱ �� �����ַ����Ϊ �����ǲ�����ʧ�ģ���ʧ�� temp ��� �ֲ�����
}


// ˫Ŀ���������
Complex& operator+=(Complex &c1, Complex &c2)
{
	c1.a += c2.a;
	c1.b += c2.b;

	return c1;
}

int main_07(void)
{

	Complex c1(1, 2);
	Complex c2(2, 4);

	// ͨ��ȫ�ֺ����ķ�ʽ���
	//Complex temp = complexAdd(c1, c2);
	//temp.printfComplex();

	// ͨ�����������صķ�ʽ�������
	//Complex temp = c1 + c2;
	//temp.printfComplex();

	Complex temp1 = c2 - c1;
	temp1.printfComplex();

	// ���þֲ������������
	Complex temp2 = c1.operator+(c2);
	temp2.printfComplex();

	int address = operator&(c2);
	printf("0x%d\n", address);



	// ǰ++ �������ʹ��
	(++c1).printfComplex();;

	return 0;
}


// ��������������ܽ᣺
// 1.C++�������û��Լ������µ��������ֻ�ܶ����е�C++���������
// 2.C++�������ص������
// 3.���ز��ܸı������������󣨼����������ĸ���
// 4.���ز��ܸı�����������ȼ�
// 5.���ز��ܸı�������Ľ����
// 6.����������ĺ���������Ĭ�ϵĲ���(����͸ı�����������ĸ�������ǰ���3��ì��)
// 7.���ص������������û����Զ������͵Ķ���һ��ʹ�ã����������Ӧ��һ���������(�������������)
// 8.���������������һ��������أ������������⣬����� "=" �� "&" �����û�����
// 9.Ӧ��ʹ����������Ĺ������Ƹ�����������ڱ�׼��������ʱ��ʵ�ֵĹ��ܡ�
// 10.��������غ�����������ĳ�Ա������Ҳ�����������Ԫ�������������Ǽȷ���ĳ�Ա����Ҳ������Ԫ��������ͨ����