#include <stdio.h>
#include <stdlib.h>

#if 1  // ע�⣺Ԥ���� ������㲻��ʹ�����Ű���������

void fff() {
	printf("fff ����������\n");
}

void ggg() {
	printf("ggg ����������\n");
}

#endif
void ff() {
	printf("ff ����������\n");
}


int main_(void) {

#if 1  // Ԥ������������� ʹ������ ����
	{
		fff();
		ggg();
	}
	#endif

	return 0;
}
