#include <stdio.h>

int g_val; //����
int g_val = 20; // û������ģ����Ƕ���, ����C++�� ������

struct student
{
	int age;
	char name[20];

};


// C�����޷���ֵ�ĺ���
f() {
	return 10;
}

void g(int a) {
}

int main_03_03(void) {

	int a = 10;
	int b = 20;

	printf("%d, %d\n", a, b);


    struct student s; // ��C������ ��ǰ�� ����Ҫ ��� struct

	g(10, 20, 30); // C���� ����ഫ����Ҳ�ǲ��ᱨ������C++�в�������ΪC++��ǿ���͵�����

	return 0;
}