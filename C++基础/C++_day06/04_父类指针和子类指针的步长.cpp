#include<iostream>

using namespace std;

class Parent_p
{
public:
	Parent_p(int a)
	{
		this->a = a;
	}

	virtual void print() {
		cout << "Parent :: print  a=" << this->a << endl;
	}

private:
	int a;
};

class Child_c : public Parent_p
{
public:
	Child_c(int a) : Parent_p(a)
	{
		this->b = a;
	}

	virtual void print() {
		cout << "Child :: print  b=" << this->b << endl;
	}

private:
	int b;
};

int main_04(void)
{

	Child_c arr[3] = { Child_c(1), Child_c(2), Child_c(4) };

	Parent_p *pp = &arr[0];
	Child_c *cp = &arr[0];

	pp->print();
	cp->print();

	pp++;
	cp++;

	cp->print();
	pp->print(); // ����ִ��һ�����󱨴�


	// ����ָ�� �� ����ָ�� ���� �ܽ᣺

	// ����ָ����ƶ��Ǹ������͵Ĵ�С���ƶ��ģ����ԣ���������󱻸���ָ�������õ�ʱ��
	// ��ʱ�������ָ���ƶ���λ�ã��Ǹ����С��λ�ã������������С��λ�ã����Ի���ִ���

	// ���� ����ָ���ƶ���ʱ�򣬲���ʹ�ö�̬����������(Ҳ�п��ܲ����������ʵ�������Ǵ����)
	// ��ע�⣺��������븸��Ĵ�Сһ�������Ծͻ�����ƶ��������������

	return 0;
}