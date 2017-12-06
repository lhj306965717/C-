
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class AdvHero {
public :
	int id;


	char* name;
	char a[20];

public : static AdvHero instance() {
	return{ 11, "ËÅä", "Â§©" };
	}
};

int main(void) {

	AdvHero adv;

	adv.name = "liao";

	cout << adv.name << endl;

	strcpy(adv.a, "liao");

	cout << adv.a << endl;

	// æ≤Ã¨∑√Œ ∑Ω Ω
	AdvHero hero = AdvHero::instance();
	cout << hero.name << endl;

	return 0;
}