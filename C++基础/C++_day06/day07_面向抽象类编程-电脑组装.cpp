#include<iostream>

using namespace std;


// Ϊʲô  cpu  �ڴ�  �Կ� �ĺ���Ҫ�ֿ�д

// ��һְ��

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

// ��װһ�����Գ���
class Computer
{

	// ΪʲôҪ��ôд��
	// ���ͨ��дһ�������̳������������
	// ��ô��100�ֵ������ͣ���ô��Ҫд100�������̳�

	// �������ͨ������д����ô��ֻ��Ҫдһ�־Ϳ�����
	// ����ͨ���̳еķ�ʽ������Ը�ǿ

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
		cout << "Computer ����" << endl;
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
		cout << "IntelCPU ����" << endl;
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
	Card *card = new IntelCard(); // ������д����һ��������Ĭ�ϵ��õ��޲ι��캯��

	Computer *com = new Computer(cpu, memory, card);

	com->startWork(); // ��ʼ����

	delete com;

	return 0;
}