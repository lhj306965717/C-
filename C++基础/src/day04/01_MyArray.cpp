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

	// 析构函数
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

	// 声明，具体实现在外面写
	int & operator[](const int index);



	// 一种新的声明方式：类型限定符
	// 这是把整个函数修饰为const，意思是“函数体内不能对成员数据做任何改动”
	// 如果声明这个类的一个const实例，那么它就只能调用有const修饰的函数。
	int getA(int *a) const
	{
		// 在函数 括号外添加了 const ,修改成员变量就会报错
		//this->len = 20;

		return 0;
	}
	
};



//  使用 MyArray:: 域作用符
int & MyArray::operator[](const int index)
{
	if(index >= 0 && index < this->len)
	{
	    return this->space[index]; // 注意：这里返回的是 内存块的别名
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