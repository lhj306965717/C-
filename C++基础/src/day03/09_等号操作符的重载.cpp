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


		// ���ܽ���ǳ�������Է�ֹ���ͷ�
		//this->name = name;

		// Ϊ�˰�ȫ��ֻ�ܽ������
		int len = strlen(name);
		this->name = new char[len+1];
		strcpy(this->name, name);
	}
	// ������캯��
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

	// = ����������
	Student & operator=(Student &annoth)
	{
		if (this == &annoth)
		{
			return *this;
		}

		// �Ƚ�����Ŀռ���յ�
		if (this->name != NULL)
		{
			delete[] this->name; 
			this->name = NULL;
			this->id = 0;
		}

		// ���
		this->id = annoth.id;
		// ֱ�ӽ����������
		int len = strlen(annoth.name);
		this->name = new char[len + 1];
		strcpy(this->name, annoth.name);

		return *this;
	}
};


int main_09(void)
{
	Student s1(24, "�κ��");
	Student s2;

	// ����������
	s2 = s1;

	s2.printf();


	return 0;
}