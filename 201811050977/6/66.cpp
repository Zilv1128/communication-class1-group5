#include"6.h"
#include<iostream>
using namespace std;
vehicle::vehicle(int wh,float we)
{
	wheels=wh;
	weight=we;
}
vehicle::displayvehicle()
{
	cout<<"���ָ���Ϊ:"<<wheels<<endl;
	cout<<"����Ϊ:"<<weight<<"��"<<endl;
}
car::car(int pa,int wh,float we):vehicle(wh,we)
{
	passenger_load=pa;
}
car::displaycar()
{
	cout<<"С��������Ϊ:"<<passenger_load<<endl;
	displayvehicle();
}
truck::truck(int pa,float pay,int wh,float we):vehicle(wh,we)
{
	passenger_load=pa;
	payload=pay;
}
truck::displaytruck()
{
	cout<<"����������Ϊ:"<<passenger_load<<endl;
	cout<<"����������Ϊ:"<<payload<<"��"<<endl;
	displayvehicle();
}
