#include <iostream>
using namespace std;
class vehicle   //基类：汽车
{
public:
	vehicle(int wh, int we);   //构造函数
	void display();
protected:
	int wheels;//车轮个数
	int weight;//车重
};

vehicle::vehicle(int wh, int we)
{
	cout << "构造了一个汽车类！" << endl;
	wheels = wh;
	weight = we;
}
void vehicle::display()
{
	cout << "wheels=" << wheels << endl<< "weight=" << weight << endl;
}

class car :private vehicle     //小车类car私有继承
{
public:
	car(int wh, int we, int pa);
	void display();
private:
	int passenger_load;//载人数
};

car::car(int wh, int we, int pa) : vehicle(wh, we)
{
	cout << "派生了一个小汽车类！" << endl;
	passenger_load = pa;
}

void car::display()
{
	vehicle::display();
	cout << "passenger_load=" << passenger_load << endl;
}

class truck :private vehicle    //卡车类truck私有继承
{
public:
	truck(int wh, int we, int pa, int pay);
	void display();
private:
	int passenger_load;//载人数
	int payload;//载重量
};

truck::truck(int wh, int we, int pa, int pay) :vehicle(wh, we)
{
	cout << "派生了一个卡车类！" << endl;
	passenger_load = pa;
	payload = pay;
}
void truck::display()
{
	vehicle::display();
	cout << "passenger_load=" << passenger_load << endl<< "payload=" << payload << endl;
}

int main()
{
	class vehicle v1(10, 18);
	v1.display();
	cout<<  "***************************************" << endl;
	class car c1(4, 10, 6);
	c1.display();
	cout << "***************************************" << endl;
	class truck t1(12, 30, 3, 50);
	t1.display();
	cout << "***************************************" << endl;
	return 0;
}

