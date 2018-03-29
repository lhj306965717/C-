#include<iostream>
#include"Cat.h"

using namespace std;

Cat::Cat()
{
	// 构造函数
}

Cat::~Cat()
{
	// 析构函数
	cout << "Cat 被析构..." << endl;
}

void Cat::voice()
{
	cout << "小猫开始哭了..." << endl;
}