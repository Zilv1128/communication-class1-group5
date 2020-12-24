#include <iostream>
#include "car.h"
#include "truck.h"
using namespace std;

int main()
{
    vehicle v1(4, 2000);
    car c1(4, 1500, 5);
    truck t1(8, 5000, 2, 1000);

    cout << v1.get_wheels() << ' ' << v1.get_weight() << endl;
    cout << c1.get_wheels() << ' ' << c1.get_weight() << ' ' << c1.get_passenger_load() << endl;
    cout << t1.get_wheels() << ' ' << t1.get_weight() << ' ' << t1.get_passenger_load() << ' ' << t1.get_payload() << endl;

}