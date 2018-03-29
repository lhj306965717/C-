#include<iostream>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

using namespace std;

int main_day07(void)
{

	Animal* cat = new Cat();
	Animal* dag = new Dag();

	cat->voice();
	dag->voice();

	delete cat;
	delete dag;

	return 0;
}