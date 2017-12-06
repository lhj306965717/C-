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

// 拷贝构造是初始化的时候才调用，之前是没有垃圾的，所以不用考虑垃圾回收
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
		cout << this->str << " -> 执行了析构" << endl;
		delete this->str;
		this->len = 0;
		this->str = NULL;
	}
}

//--------------------   操作符重载  -----------------------

//注意-注意：一定要返回一个对象，而不能返回引用，因为temp是一个临时值，返回引用会出现错误，因为temp被释放了
MyString operator+(const MyString &s1, const MyString &s2)
{
	MyString temp;

	temp.str = new char[s1.len + s2.len + 1]; // 申请一个堆内存
	temp.len = s1.len + s2.len;
	
	// 一定要进行清空,因为下面使用的 strnact
	memset(temp.str, 0, temp.len);

	//strncat(temp.str, s1.str, s1.len);
	strcpy(temp.str, s1.str); //如果先使用了 strcpy ，可以直接省略 memset 函数的调用
	
	strncat(temp.str, s2.str, s2.len);

	return temp;
}

ostream & operator<<(ostream &os, const MyString &s)
{
	os << s.str << endl;
	return os;
}


// 注意： MyString &s 是需要 写 操作的，所以不能声明为 const
istream & operator>>(istream &is, MyString &s)
{
	if (s.str != NULL)
	{
		s.len = 0;
		delete[] s.str;
		s.str = NULL;
	}

	// 因为长度是不确定的，所以没法无限制输入，只能有一个临时值来缓存
	// 包括 string 也不能无限制输入，一旦超过缓冲值就会崩溃
	char temp_str[4096] = { 0 };

	// 注意：这里的输入是 cin
	is >> temp_str;

	int len = strlen(temp_str);

	s.len = len;
	s.str = new char[s.len + 1];

	strcpy(s.str, temp_str);

	return is;
}


// 注意：这是重载的 数组操作符
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