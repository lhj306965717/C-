#pragma once

#include<iostream>
// 注意：上下两个不能少
using namespace std;

class MyString
{
private:
	int len;
	char *str;

public:

	// 构造函数
	MyString();
	MyString(int len); // 创建一个长度是len的string对象
	MyString(const char *str); // 通过一个字符串初始化
	MyString(const MyString &another);

	// 析构函数
	~MyString();

	// 操作符重载 []
	// new char[10]
	char & operator[](const int len);

	// 操作符重载 <<
	friend ostream & operator<<(ostream &os, const MyString &s);

	// 操作符重载 >>
	friend istream & operator>>(istream &is, MyString &s);

	// 操作符重载 ==

	// 操作符重载 !=

	// 操作符重载 =
	MyString & operator=(const MyString &another);

	// 操作符重载 +
	friend MyString operator+(const MyString &s1, const MyString &s2);



	void printf();

};