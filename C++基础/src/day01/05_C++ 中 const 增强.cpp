#include<iostream>

using namespace std;

int main_05(void){

	const int a = 10; // ��C++ �� const��һ�������ĳ���

	int *p = (int *)&a; // ��һ����ȫ�� ��ֵ��һ������ȫ�� �ᱨ�쳣����ΪC++��ǿ�������ԣ�
	
	*p = 20; // ��C++ ���޷��ı�

	// ������Ϊ pָ�� ָ��ĵ�ַ������ a��ʵ�ʵ�ַ������һ����ʱ�ĵ�ַ

	cout << a << endl; // 10

	cout << *p << endl; // 20


	return 0;
}