#include <iostream>

using namespace std;

int g_val;  // bss��
// ��ΪC++��ǿ���͵����ԣ���ȫ�ֱ����Ķ�����������ǿ��
//int g_val = 20;  //data��  // ������C++ ��ȫ�ֱ�����û�ж�������������д��

struct student
{
	char name[20];
	int age;
};

void test() {

	// C++ �������ӵ� ��������
	bool flag = true;

	// true ȡֵ1��false ȡֵΪ0����ֻ��ȡ������ֵ
	cout << flag << endl;
}

int main_03(void) {

	// 1.
	// �洦�����洦ʹ�ã�������C�����У�ֻ������������ʹ�ã�����C++����ǿ
	// C�����в���������д
	for (int i = 0; i < 5; i++)
	{

	}

	// 2.
	// ��C++ ������һ���ṹ���������Ҫд��д(����ʡ��) struct �ˣ�ʵ���ϰ�struct������һ������������ʵ������˵��Ӧ���ǰ��൱�� �ṹ����ʹ���ˣ�
	student stu;
	stu.age = 24;

	std::cout << stu.age << std::endl;

	test();

	return 0;
}



// ��C++ �в��� �� û�з���ֵ�����͵� ����
// ��ΪC++��ǿ����
//f() { // ����C���Կ��Ե�д��
//	return 10;
//}