﻿
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class AdvHero {
public :
	int id;


	char* name;
	char a[20];

public : static AdvHero instance() {
<<<<<<< HEAD
	return{ 11, "廖红杰", "聊天"};
=======
	return{ 11, "�κ��", "����" };
>>>>>>> 13b84ed66fdc4bd521c8f8bcaf28af25434812aa
	}
};

int main(void) {

	AdvHero adv;

	adv.name = "liao";

	cout << adv.name << endl;

	strcpy(adv.a, "liao");

	cout << adv.a << endl;

	// 静态访问方式
	AdvHero hero = AdvHero::instance();
	cout << hero.name << endl;

	return 0;
}