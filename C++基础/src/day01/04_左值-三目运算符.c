

#include <stdio.h>
#include <stdlib.h>



// ע�⣺��������ñ��������ֱ��ʹ�� 1 �ᱨ��

int aa = 1;

void test001() {

	int a = 10;
	int b = 20;
	int c = 1;

	// ��ֵ(�ܷ��ڸ�ֵ����ߵ�ֵ����ֵ)  ��ֵ���ܷ��ڸ�ֵ���ұߵ�ֵ����ֵ��

	c = a < b ? a : b;

	//	(a < b ? a : b) = 50; // ��C�����У�����,��Ϊ�����һ����ֵ

	// �޸�Ϊ��
	*(a < b ? &a : &b) = 50; // ����� a ���� b�ĵ�ַ������Ϊ��ַ��ֵ

	printf("value=%d\n", a);
}

int main_04c(void)
{

#if 1 
	{
		test001();
	}
#endif

	printf("ִ��...\n");

	return 0;
}
