#pragma once
#include "Animal.h"

using namespace std;

class Dag : public Animal
{
public:
	Dag();
	virtual ~Dag();

	// ��� virtual ���Բ���ӣ�����˱�ʾ voice ���������һ����Ҫ���麯������Ҫʵ��
	virtual void voice(); 
};

