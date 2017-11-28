#include <iostream>

using namespace std;

class Point; // 声明 Point 类


// 需要拿到前面类，因为是从上到下编译
// 还有就是 下面 声明 友元函数的时候 使用 Test,那么必要要将Test写到前面，声明Test是一个空间(类)
class Test {

	// 当前函数是在类外面的，如果调用这个函数计算，会不停的调用 Point的方法进行压栈和出栈

	// 需要在类中声明 
public:
	double PointDistance(Point &p1, Point &p2); // 这里使用到了 Point，上面需要声明下
};


class Point
{
public:
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	int getX()
	{
		return this->x;
	}

	int getY()
	{
		return this->y;
	}

	// 通过友元的方式
	// 这个声明没有强制要求写在那里，私有，公有都无所谓
	// 声明全局函数 PointDistance 是我类Point类的一个友元函数
	friend double Test::PointDistance(Point &p1, Point &p2);


private:
	int x;
	int y;
};

// 把具体实现从Test中提出来，然后 这个方法中的 Point对象才能直接引用 x,y
double Test::PointDistance(Point &p1, Point &p2)
{
	double sum;
	//int s_x = p1.getX() - p2.getX();
	//int s_y = p1.getY() - p2.getY();

	// 有没有把法在这里通过Point对象 直接拿到X,Y值，不需要频繁的调用的方法
	// 通过声明友元函数的方式
	int s_x = p1.x - p2.y;
	int s_y = p1.y - p2.y;

	sum = sqrt(s_x*s_x + s_y*s_y);

	return sum;
}

class T {
public:
	int add(int a, int b);// 可以声明函数，但是没有实现的函数无法被调用
};

int main_06(void)
{
	Point p1(5, 10);
	Point p2(10, 20);


	//int sum = PointDistance(p1, p2);

	//cout << sum << endl;

	//T t;
	//t.add(1, 2); // 可以创建对象，但是不能调用没有实现的函数

	return 0;
}

// 总结：友元的好处 是 减少了 函数的频繁调用，但是它破坏了类的函数封装性，是私有变量可能会被改变
// 但是不推荐经常使用，就像go to 语句，

// 友元具有单向性，且不能被继承，不具有传递性


