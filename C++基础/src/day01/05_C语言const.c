#include <stdio.h>

int main_05(void) {

	const int a = 10;  // ��C������ const�������� α����

	int *p = &a;

	*p = 20;

	printf("%d\n", a); // �����޸���һ��α����

	return 0;
}