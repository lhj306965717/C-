#include<iostream>

using namespace std;


// Ϊ�˱������ǰ�Ĵ����г�ͻ��������� _s
class Parent_s
{
public:
	Parent_s(int a)
	{
		cout << "Parent(int a)" << endl;
		this->a = a;

		print();
	}

	virtual void print()
	{
		cout << "Parent :: void print()...  a=" << this->a << endl;
	}

private:
	int a;
};


class Child_s : public Parent_s
{
public:
	// ��ʾ ���� b �� Child�Ĺ������
	Child_s(int a, int b) : Parent_s(b)//�ڵ��ø��๹������ʱ�򣬻Ὣvptrָ�뵱������������
	{
		cout << "Child(int a, int b)..." << endl;
		this->a = a;
		this->b = b;
	}

	// ���⣺Ϊʲô�ڸ���Ĺ��캯���е��õ�print������ ���õĸ����е�
	// ��Ϊ�ڹ��������ʱ����ȹ��츸��(�����л����������ڴ�ռ�)����ʱ����ĸ��࣬
	// ��ô��ʱ��vptrָ�����ʱָ������麯���������໹û�б�������������Ե��õ��Ǹ���ķ���
	// ��������ɺ󣬹��������ʱ�򣬴�ʱvptrָ��Ż�����ָ��������麯�������ڵ�ַ��
	// ����vptrָ���ʼ���ǴӸ���ı�ָ������ı�

	virtual void print()
	{
		cout << "Child :: void print()...  b=" << this->b << endl;

	}

private:
	int a;
	int b;
};

int main_03(void)
{
	Parent_s *p = new Child_s(1, 2);
	
	p->print(); // ��ʱ���õ��������print����

	delete p;

	return 0;
}