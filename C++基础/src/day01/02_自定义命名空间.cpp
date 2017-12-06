#include <iostream>

using namespace std;

// 注意：namespace 是关键字
// 定义一个命名空间
namespace spaceA
{
	int g_a = 10;

	namespace spaceB { // 可以嵌套
	
		struct teacher
		{
			int id;
			char name[20];
		};
	}

	// 已经测试过，但是不常用
	using namespace spaceB; // 在A 中使用B，声明后在使用中，就不需声明 B 了
}


int main_02(void)
{

	using namespace spaceA;

	cout << g_a << endl; // 使用

	// 嵌套的命名空间声明  '::' 是域操作符
	// using namespace spaceA::spaceB; // 单个变量声明
	using namespace spaceB; // 两种声明都一样,

	struct teacher t1;

	return 0;
}