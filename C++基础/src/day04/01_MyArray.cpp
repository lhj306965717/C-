#include<iostream>


using namespace std;


class MyArray
{
private:
	int len;
	int *space;

public:
	MyArray() {}

	MyArray(int len)
	{
		this->len = len;

		if (this->space != NULL)
		{
			delete this->space;
		}

		this->space = new int[len];
	}

	MyArray(const MyArray &another)
	{
		this->len = another.len;

		if (this->space != NULL)
		{
			delete[] this->space;
		}

		this->space = new int[another.len];

		for (int i = 0; i < another.len; i++)
		{
			*(space + i) = another.space[i];
		}
	}

	// ��������
	~MyArray()
	{
		this->len = 0;
		delete this->space;
	}

	void setData(int index, int data)
	{
		if (this->space != NULL && index < len && index >= 0)
		{
			this->space[index] = data;
			//cout << *(this->space + index) << endl;
		}
	}

	int getData(int index)
	{
		if (index >= 0 && index < len)
		{
			return this->space[index];
		}

		return 0;
	}
	int getLen()
	{
		return len;
	}

	MyArray & operator=(const MyArray &another)
	{
		if (this == &another)
		{
			return *this;
		}

		if (this->space != NULL)
		{
			delete this->space;
			this->space = NULL;
			this->len = 0;
		}

		this->space = new int(sizeof(int) * another.len);

		for (int i = 0; i < another.len; i++)
		{
			*(space + i) = another.space[i];
		}

		return *this;
	}

	// ����������ʵ��������д
	int & operator[](const int index);



	// һ���µ�������ʽ�������޶���
	// ���ǰ�������������Ϊconst����˼�ǡ��������ڲ��ܶԳ�Ա�������κθĶ���
	// �������������һ��constʵ������ô����ֻ�ܵ�����const���εĺ�����
	int getA(int *a) const
	{
		// �ں��� ����������� const ,�޸ĳ�Ա�����ͻᱨ��
		//this->len = 20;

		return 0;
	}
	
};



//  ʹ�� MyArray:: �����÷�
int & MyArray::operator[](const int index)
{
	if(index >= 0 && index < this->len)
	{
	    return this->space[index]; // ע�⣺���ﷵ�ص��� �ڴ��ı���
	}
	else
	{
		int a = 0;
	    return a;
	}
}

int main_01(void)
{

	MyArray arr(10);

	for (int i = 0; i < 10; i++)
	{
		//arr.setData(i, i + 10);
		arr[i] = i + 10;
	}

	cout << "++++++++++++++++" << endl;

	for (int j = 0; j < 10; j++)
	{
		cout << arr.getData(j) << ", ";
	}

	cout << endl;


	 int a = 10;

	int aa = arr.getA(&a);

	return 0;
}