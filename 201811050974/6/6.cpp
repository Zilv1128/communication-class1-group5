#include <iostream>
using namespace std;
class vehicle   //���ࣺ����
{
public:
	vehicle(int wh, int we);   //���캯��
	void display();
protected:
	int wheels;//���ָ���
	int weight;//����
};

vehicle::vehicle(int wh, int we)
{
	cout << "������һ�������࣡" << endl;
	wheels = wh;
	weight = we;
}
void vehicle::display()
{
	cout << "wheels=" << wheels << endl<< "weight=" << weight << endl;
}

class car :private vehicle     //С����car˽�м̳�
{
public:
	car(int wh, int we, int pa);
	void display();
private:
	int passenger_load;//������
};

car::car(int wh, int we, int pa) : vehicle(wh, we)
{
	cout << "������һ��С�����࣡" << endl;
	passenger_load = pa;
}

void car::display()
{
	vehicle::display();
	cout << "passenger_load=" << passenger_load << endl;
}

class truck :private vehicle    //������truck˽�м̳�
{
public:
	truck(int wh, int we, int pa, int pay);
	void display();
private:
	int passenger_load;//������
	int payload;//������
};

truck::truck(int wh, int we, int pa, int pay) :vehicle(wh, we)
{
	cout << "������һ�������࣡" << endl;
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

