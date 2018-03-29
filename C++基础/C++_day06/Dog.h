#pragma once
#include "Animal.h"

using namespace std;

class Dag : public Animal
{
public:
	Dag();
	virtual ~Dag();

	// 这个 virtual 可以不添加，添加了表示 voice 这个函数是一个需要纯虚函数，需要实现
	virtual void voice(); 
};

