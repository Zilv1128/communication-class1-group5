#include"6.h"
#include<iostream>
using namespace std;
void main()
{
	vehicle v(0,0);
	car c(5,4,1.05);
	truck t(3,40,12,10);
	v.displayvehicle();
	cout<<endl;
	c.displaycar();
	cout<<endl;
	t.displaytruck();
}