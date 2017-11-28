#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "MyString.h"

using namespace std;

MyString::MyString()
{
	this->len = 0;
	this->str = NULL;
}

MyString::MyString(const char *str)
{
	if (str == NULL)
	{
		this->len = 0;
		this->str = new char[0+1];
		strcpy(this->str, "");
	}else
	{ 
	    this->len = strlen(str);

		this->str = new char[this->len + 1];

		strcpy(this->str, str);
	}
}

MyString::MyString(const int len)
{
	if (len == 0)
	{
		this->len = 0;
		this->str = NULL;
	}
	else
	{
		this->len = len;
		this->str = new char[this->len + 1];
	}
}

// ���������ǳ�ʼ����ʱ��ŵ��ã�֮ǰ��û�������ģ����Բ��ÿ�����������
MyString::MyString(const MyString &another)
{
	cout << another.str << endl;

	this->len = another.len;
	this->str = new char[this->len + 1];
	strcpy(this->str, another.str);
}

MyString::~MyString()
{
	if (this->str != NULL)
	{
		cout << this->str << " -> ִ��������" << endl;
		delete this->str;
		this->len = 0;
		this->str = NULL;
	}
}

//--------------------   ����������  -----------------------

//ע��-ע�⣺һ��Ҫ����һ�����󣬶����Ƿ���һ�����ã���Ϊtemp��һ����ʱֵ���������û���ִ�����Ϊtemp���ͷ���
MyString operator+(const MyString &s1, const MyString &s2)
{
	MyString temp;

	temp.str = new char[s1.len + s2.len + 1]; // ����һ�����ڴ�
	temp.len = s1.len + s2.len;
	
	// һ��Ҫ�������,��Ϊ����ʹ�õ� strnact
	memset(temp.str, 0, temp.len);

	//strncat(temp.str, s1.str, s1.len);
	strcpy(temp.str, s1.str); //�����ʹ���� strcpy ������ֱ��ʡ�� memset �����ĵ���
	
	strncat(temp.str, s2.str, s2.len);

	return temp;
}

ostream & operator<<(ostream &os, const MyString &s)
{
	os << s.str << endl;
	return os;
}


// ע�⣺ MyString &s ����Ҫ д �����ģ����Բ�������Ϊ const
istream & operator>>(istream &is, MyString &s)
{
	if (s.str != NULL)
	{
		s.len = 0;
		delete[] s.str;
		s.str = NULL;
	}

	// ��Ϊ�����ǲ�ȷ���ģ�����û�����������룬ֻ����һ����ʱֵ������
	// ���� string Ҳ�������������룬һ����������ֵ�ͻ����
	char temp_str[4096] = { 0 };

	// ע�⣺����������� cin
	is >> temp_str;

	int len = strlen(temp_str);

	s.len = len;
	s.str = new char[s.len + 1];

	strcpy(s.str, temp_str);

	return is;
}


// ע�⣺�������ص� ���������
char & MyString::operator[](const int index)
{
	return this->str[index];
}

MyString & MyString::operator=(const MyString &another)
{
	if (this == &another)
	{
		return *this;
	}

	if (this->str != NULL)
	{
		this->len = 0;
		delete[] this->str;
		this->str = NULL;
	}
	
	this->len = another.len;
	this->str = new char[this->len + 1];
	strcpy(this->str, another.str);
	
	return *this;
}

void MyString::printf()
{
	cout << this->str << "   :  " << this->len << endl;
}