#include <stdio.h>

enum season  //����ö�����ͣ����ƽṹ��
{
	A,
	B,
	C = 110,
	D,
	E
};

int main(void) {

	// ��C�����У�ʹ�ò��� ö�� ��ֵ���ᱨ��������C++ �в���
	enum season s = 10; // ����ö�ٱ���

	printf("%d\n", s); // ö��ʹ��

	enum season a = D;

	// ֱ��ʹ��
	printf("%d\n", B); 
	printf("%d\n", a);

	return 0;
}