#pragma once

#include<iostream>
// ע�⣺��������������
using namespace std;

class MyString
{
private:
	int len;
	char *str;

public:

	// ���캯��
	MyString();
	MyString(int len); // ����һ��������len��string����
	MyString(const char *str); // ͨ��һ���ַ�����ʼ��
	MyString(const MyString &another);

	// ��������
	~MyString();

	// ���������� []
	// new char[10]
	char & operator[](const int len);

	// ���������� <<
	friend ostream & operator<<(ostream &os, const MyString &s);

	// ���������� >>
	friend istream & operator>>(istream &is, MyString &s);

	// ���������� ==

	// ���������� !=

	// ���������� =
	MyString & operator=(const MyString &another);

	// ���������� +
	friend MyString operator+(const MyString &s1, const MyString &s2);



	void printf();

};