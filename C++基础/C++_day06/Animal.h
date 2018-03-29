#pragma once

#include<iostream>

using namespace std;

class Animal
{
public:
	// 让子类继承并实现
	virtual void voice() = 0;

	Animal();  // 构造函数

	
	// 注意：如果写成 纯虚析构函数 ，那么需要写一个 .cpp 文件来实现

	virtual ~Animal(); // 析构函数，如果当实现类中出现了析构函数需要释放，那么在父类中就要使用，
	                   // 这样才可以使用多态机制
};


