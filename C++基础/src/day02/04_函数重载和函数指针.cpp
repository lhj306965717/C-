#include <iostream>

using namespace std;

void funca(int a, int b) {
	cout << a << " : " << b << endl;
}

void funca(int a, int b, int c) {
	cout << a << " : " << b << " : " << c << endl;
}

typedef void(*MY_FUNC)(int, int); // ����һ������ָ��

// ע�⣺�����Ҫ�� ��������ָ�����͵�
typedef void (my_func)(int, int); // ����һ����������

int main_04(void) {

	my_func * fc = NULL; // ����һ������ָ��

	fc = funca;

	fc(10, 20);


	MY_FUNC fp = NULL;

	fc = funca;

	fc(100, 200);

	//fc(100, 200, 300); // �����޷�ƥ�䵽���������ĺ���

	//  �ܽ᣺����ָ�벻��ʵ�� ��������

	// ʵ�����ڸ�����ָ�븳ֵ��ʱ���ǻᷢ����������ƥ���
	// �ڵ��ú���ָ���ʱ�������õĺ������Ѿ��̶��ˣ�


	return 0;
}