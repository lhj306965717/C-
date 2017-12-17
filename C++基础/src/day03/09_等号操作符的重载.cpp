#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


class Student
{
private:
	int id;
	char *name;

public:
	Student() {}

	Student(int id, char *name)
	{
		this->id = id;


		// 不能进行浅拷贝，以防止被释放
		//this->name = name;

		// 为了安全，只能进行深拷贝
		int len = strlen(name);
		this->name = new char[len+1];
		strcpy(this->name, name);
	}
	// 深拷贝构造函数
	Student(const Student &annoth)
	{
		this->id = annoth.id;
		int len = strlen(annoth.name);
		this->name = new char[len + 1];
		strcpy(this->name, annoth.name);
	}

	void printf()
	{
		cout << this->id << " : " << this->name << endl;
	}

	// = 操作符重载
	Student & operator=(Student &annoth)
	{
		if (this == &annoth)
		{
			return *this;
		}

		// 先将自身的空间回收掉
		if (this->name != NULL)
		{
			delete[] this->name; 
			this->name = NULL;
			this->id = 0;
		}

		// 深拷贝
		this->id = annoth.id;
		// 直接进行深拷贝操作
		int len = strlen(annoth.name);
		this->name = new char[len + 1];
		strcpy(this->name, annoth.name);

		return *this;
	}
};


int main_09(void)
{
	Student s1(24, "廖红杰");
	Student s2;

	// 操作符重载
	s2 = s1;

	s2.printf();


	return 0;
}