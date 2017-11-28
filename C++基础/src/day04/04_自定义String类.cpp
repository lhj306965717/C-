#include<iostream>
#include <string>
#include "MyString.h"

using namespace std;


int main(void)
{

//	string s1("123");
//	string s2 = "abc"; // 进行了操作符重载的

	MyString s1("123");
	MyString s2("abc");
	MyString s3;
	MyString s4;

	cout << s1 << s2;

	s3 = s2;

	cout << s3;


	//cin >> s4;
	//cout << s4;

	MyString temp = s1 + s2;

	//temp.printf();



	return 0;
}