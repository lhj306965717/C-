#include <iostream>

using namespace std;

// ע�⣺namespace �ǹؼ���
// ����һ�������ռ�
namespace spaceA
{
	int g_a = 10;

	namespace spaceB { // ����Ƕ��
	
		struct teacher
		{
			int id;
			char name[20];
		};
	}

	// �Ѿ����Թ������ǲ�����
	using namespace spaceB; // ��A ��ʹ��B����������ʹ���У��Ͳ������� B ��
}


int main_02(void)
{

	using namespace spaceA;

	cout << g_a << endl; // ʹ��

	// Ƕ�׵������ռ�����  '::' ���������
	// using namespace spaceA::spaceB; // ������������
	using namespace spaceB; // ����������һ��,

	struct teacher t1;

	return 0;
}