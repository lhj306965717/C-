#include <iostream>

using namespace std;


class Test
{
private:
	int a;
public:

	Test(int a)
	{
		this->a = a;
	}

	// ���ȣ����������ڶ����ڴ��У������� ������
	// ���� ��������ôͨ����������ֵ���أ�

	// ��ʵ�������ڱ������ int getA(Test* const pthis){ }
	// ͨ��������ĵ�ַ���صĴ��ݽ����ˣ����Զ����еĺ������ܷ��ض����еı���
	// �������ָ���� һ��ָ�볣�� ��ֻ���޸���ָ���ַ��ֵ�������޸�ָ��ĵ�ַ
	int getA(/*Test* const this*/)
	{
		this->a = 100;

		return a;
	}

	// ��Ͼ�̬�ܽ᣺

	// 1.��̬��Ա���������壬��������Ϣ�������ݹ�ͨ�������ڹ���̬���ݳ�Ա����ɶԾ�̬���ݳ�Ա�ķ�װ

	// 2.��̬��Ա����ֻ�ܷ��ʾ�̬���ݳ�Ա��ԭ�򣺷Ǿ�̬��Ա�������ڵ�����thisָ�뵱����������
	//   ���Ǿ�̬��Ա���������࣬�������ڶ���û��thisָ��

	// ��java һ������̬���� �в��ܷ��ʷǾ�̬ ��Ա�������߷���
};


class Text
{
public:
	Text(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	void print()
	{
		cout << "a=" << this->a << "  b=" << this->b << endl;
	}

	int getA()
	{
		return this->a;
	}

	int getB()
	{
		return this->b;
	}

	// �ṩ��Ա����
	Text TextAdd(Text &another)
	{
		Text temp(this->a + another.getA(), this->b + another.getB());
		return temp;
	}

	// ʵ�� +=
	Text& TextAdd2(Text &another)
	{
		this->a += another.a;
		this->b += another.b;

		// return this;  ע�⣺���ﲻ�ܷ��� this, ��Ϊ this ��һ��ָ�룬

		return *this; // ֻ�ܷ������ָ����ָ���ֵ ----> �������
	}

private:
	int a;
	int b;
};

// �ṩȫ�ֵ���Ӻ���
Text TextAdd(Text &t1, Text &t2)
{
	Text temp(t1.getA() + t2.getA(), t1.getB() + t2.getB());
	return temp;
}

int main_05(void)
{
	Text t1(10, 20);
	Text t2(100, 200);

	Text sun = TextAdd(t1, t2);

	sun.print();

	cout << "*************************************" << endl;

	Text t3 = t1.TextAdd(t2);

	t3.print();

	cout << "*************************************" << endl;

	// ���ڷ��ص��ǵ�ǰ�������Կ�����ʽ����
	t1.TextAdd2(t2).TextAdd2(t2).print();

	return 0;
}