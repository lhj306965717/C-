#include<iostream>

using namespace std;


// 为什么  cpu  内存  显卡 的函数要分开写

// 单一职责

class CPU
{
public:
	virtual void caculate() = 0;
};

class Memory
{
public:
	virtual void storage() = 0;
};

class Card
{
public:
	virtual void display() = 0;
};

// 组装一个电脑出来
class Computer
{

	// 为什么要这么写？
	// 如果通过写一个类来继承上面的三个类
	// 那么有100种电脑类型，那么就要写100种类来继承

	// 但是如果通过这样写，那么就只需要写一种就可以了
	// 而且通过继承的方式，耦合性更强

public:
	Computer(CPU *cpu, Memory *memory, Card *card)
	{
		this->cpu = cpu;
		this->memory = memory;
		this->card = card;
	}

	void startWork()
	{
		this->cpu->caculate();
		this->memory->storage();
		this->card->display();
	}

	virtual ~Computer() 
	{
		cout << "Computer 析构" << endl;
	};

private:
	CPU *cpu;
	Memory *memory;
	Card *card;
};


class IntelCPU : public CPU
{
public:
	void caculate()
	{
		cout << "CPU---> caculate " << endl;
	}

	~IntelCPU()
	{
		cout << "IntelCPU 析构" << endl;
	}
};

class IntelMemory : public Memory
{
public:
	void storage()
	{
		cout << "Memory----> storage" << endl;
	}
};

class IntelCard : public Card
{
public:
	void display()
	{
		cout << "Card---> display" << endl;
	}
};

int main(void)
{
	CPU *cpu = new IntelCPU;
	Memory *memory = new IntelMemory;
	Card *card = new IntelCard(); // 这两种写法都一样，都是默认调用的无参构造函数

	Computer *com = new Computer(cpu, memory, card);

	com->startWork(); // 开始工作

	delete com;

	return 0;
}