#pragma once

#include<iostream>
#include"Animal.h"

using namespace std;

class Cat : public Animal
{
public:
	Cat();
	virtual ~Cat();

	virtual void voice();
};
