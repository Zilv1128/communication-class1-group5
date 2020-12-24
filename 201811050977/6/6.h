#include<iostream>
using namespace std;
class vehicle
{
public:
	vehicle(int wh,float we);
	displayvehicle();
private:
	int wheels;
	float weight;
};
class car:private vehicle
{
public:
	car(int pa,int wh,float we);
	displaycar();
private:
	int passenger_load;
};
class truck:private vehicle
{
public:
	truck(int pa,float pay,int wh,float we);
	displaytruck();
private:
	int passenger_load;
	float payload;
};