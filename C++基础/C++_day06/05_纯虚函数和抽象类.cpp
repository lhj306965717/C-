#include<iostream>

using namespace std;


// ͼ����
class Shape
{
public:
	// һ����ͼ������ķ���
	// ��ʾͼ��������һ������getArea()�� ����һ�����麯����û�к���ʵ��
	virtual double getArea() = 0; // ����0 ����д���� �﷨Ҫ��
};

// �ܽ᣺

// 1. ���˵һ���࣬ӵ��һ�����麯�����ͳ��������һ��������
//    �������������û�г�Ա���ԣ�ֻҪ������д��麯��������һ�������࣬��������ǲ��ܹ�ʵ������(�����ܴ���������Ķ���)

// 2. ���˵һ����ͨ�࣬�̳�ӵ�д��麯�����࣬����Ҫ��д����麯����
//    �������д���麯������Ȼ��һ�������࣬�Ҳ��ܱ�ʵ������
//    �����ʵ����������Ҫ��д������������д��麯��

// ��java�е� ������ һ����

// ���ε����(������)
class Rect : public Shape
{
private:
	int side;
public:
	Rect(int side)
	{
		this->side = side;
	}

	virtual double getArea()
	{
		return side*side;
	}
};

// Բ�����
class Circle : public Shape
{
private:
	int r;
public:
	Circle(int r)
	{
		this->r = r;
	}
	virtual double getArea()
	{
		return 3.14*r*r;
	}
};

int main_05(void)
{
	// 
	Shape *sp1 = new Rect(10);
	double s1 = sp1->getArea();
	cout << "���������=" << s1 << endl;

	Shape *sp2 = new Circle(4);
	double s2 = sp2->getArea();
	cout << "Բ���=" << s2 << endl;

	return 0;
}