#include <iostream>

using namespace std;

void pringAB(int a, int b) {
	cout << "a=" << a << "b=" << b << endl;
}

// ��ͣ���ظ����ã�
// ����ͨ�� inline ���������� �궨�������ĺ�����ֱ����forѭ����չ��
// �൱��
inline void printAC(int a, int b){
	cout << "a=" << a << "  b=" << b << endl;
}

int main_01(void) {

	int a = 10, b = 20;

	for (int i = 0; i < 100; i++)
	{
		a++;
		b++;

		//pringAB(a, b);

		// �������ĺô��ǣ����� ������ ѹջ�ͳ�ջ�������������

		printAC(a, b); // �ڱ����ʱ�򣬻��printAC�еĴ���չ��

		// Ҳֻ�� ������������ٵ�ʱ�򣬱������Ż���ô�������̫��(д��inlineҲû�� )��Ҳ������ô��
	}

	return 0;
}