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
	cout<<"车轮个数为:"<<wheels<<endl;
	cout<<"车重为:"<<weight<<"吨"<<endl;
}
car::car(int pa,int wh,float we):vehicle(wh,we)
{
	passenger_load=pa;
}
car::displaycar()
{
	cout<<"小车载人数为:"<<passenger_load<<endl;
	displayvehicle();
}
truck::truck(int pa,float pay,int wh,float we):vehicle(wh,we)
{
	passenger_load=pa;
	payload=pay;
}
truck::displaytruck()
{
	cout<<"卡车载人数为:"<<passenger_load<<endl;
	cout<<"卡车载重量为:"<<payload<<"吨"<<endl;
	displayvehicle();
}
