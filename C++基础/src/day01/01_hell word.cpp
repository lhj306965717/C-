
#include<iostream>

// ������ʹ�÷�ʽ
// using ��ʹ�õ���˼
using namespace std;  // �����ռ䣬������java���е���

int main_0(void)
{
	// cout ���Ǻ���Ļ�� endl ���ǻس�
	// ��ô����仰�أ�
	// �ǽ� �ַ��� ���� ����Ļ
	cout << "hello word" << endl;

	int a;

	// ���������� a
	cin >> a;

	cout << "ֵ��" << a << endl;

	return 0;
}


#if 0
{
	//�ڶ��ַ�ʽ
	// ���������ռ��е�һ����������һ������һ����������ȫ����������
	using std::cout;
	using std::cin;
	using std::endl;
}
#endif

#if 0
{
	// ��һ�ַ�ʽ
	// ֱ��ʹ�õ����ͣ������������ռ�
	std::cout << "��ã�����..." << std::endl;
}
#endif

// C����д��
#if 0
{
#include<stdio.h>

int main()
{
	printf("hello word\n");

	return 0;
}
}
#endif
