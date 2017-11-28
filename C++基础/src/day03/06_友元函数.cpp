#include <iostream>

using namespace std;

class Point; // ���� Point ��


// ��Ҫ�õ�ǰ���࣬��Ϊ�Ǵ��ϵ��±���
// ���о��� ���� ���� ��Ԫ������ʱ�� ʹ�� Test,��ô��ҪҪ��Testд��ǰ�棬����Test��һ���ռ�(��)
class Test {

	// ��ǰ��������������ģ������������������㣬�᲻ͣ�ĵ��� Point�ķ�������ѹջ�ͳ�ջ

	// ��Ҫ���������� 
public:
	double PointDistance(Point &p1, Point &p2); // ����ʹ�õ��� Point��������Ҫ������
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

	// ͨ����Ԫ�ķ�ʽ
	// �������û��ǿ��Ҫ��д�����˽�У����ж�����ν
	// ����ȫ�ֺ��� PointDistance ������Point���һ����Ԫ����
	friend double Test::PointDistance(Point &p1, Point &p2);


private:
	int x;
	int y;
};

// �Ѿ���ʵ�ִ�Test���������Ȼ�� ��������е� Point�������ֱ������ x,y
double Test::PointDistance(Point &p1, Point &p2)
{
	double sum;
	//int s_x = p1.getX() - p2.getX();
	//int s_y = p1.getY() - p2.getY();

	// ��û�аѷ�������ͨ��Point���� ֱ���õ�X,Yֵ������ҪƵ���ĵ��õķ���
	// ͨ��������Ԫ�����ķ�ʽ
	int s_x = p1.x - p2.y;
	int s_y = p1.y - p2.y;

	sum = sqrt(s_x*s_x + s_y*s_y);

	return sum;
}

class T {
public:
	int add(int a, int b);// ������������������û��ʵ�ֵĺ����޷�������
};

int main_06(void)
{
	Point p1(5, 10);
	Point p2(10, 20);


	//int sum = PointDistance(p1, p2);

	//cout << sum << endl;

	//T t;
	//t.add(1, 2); // ���Դ������󣬵��ǲ��ܵ���û��ʵ�ֵĺ���

	return 0;
}

// �ܽ᣺��Ԫ�ĺô� �� ������ ������Ƶ�����ã��������ƻ�����ĺ�����װ�ԣ���˽�б������ܻᱻ�ı�
// ���ǲ��Ƽ�����ʹ�ã�����go to ��䣬

// ��Ԫ���е����ԣ��Ҳ��ܱ��̳У������д�����


