#include<iostream>

using namespace std;

class Parent
{
public:
	virtual void func() {
		cout << "Parent::func()..." << endl;
	}

private:
	int a;
};

class Parent2
{
	void func() {
		cout << "Parent2::func()..." << endl;
	}

private:
	int a;
};

int main_02(void)
{
	Parent p1;

	cout << "Parent��С��" << sizeof(p1) << endl;

	Parent2 p2;

	cout << "Parent2��С��" << sizeof(p2) << endl;

	// ͨ����ӡ������֣� ��һ����8���ֽڣ��ڶ�����4���ֽڣ�ǡ��˵�����ڴ���һ��ָ��Ĵ�С����vptr

	return 0;
}