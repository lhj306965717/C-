#include<iostream>
#include "Dog.h"

using namespace std;

Dag::Dag() 
{

}

Dag::~Dag()
{
	cout << "Dag 被析构..." << endl;
}

void Dag::voice()
{
	cout << "小狗哭了" << endl;
}