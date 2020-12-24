#ifndef __CAR_
#define __CAR_

#include "vehicle.h"
class car : private vehicle
{
private:
    int passenger_load;

public:
    car(int Wheels = 0, int Weight = 0, int Passenger_load = 0) : vehicle(Wheels, Weight)
    {
        passenger_load = Passenger_load;
    }

    
    int get_wheels(void)
    {
        return wheels;
    }

    int get_weight(void)
    {
        return weight;
    }

    int get_passenger_load()
    {
        return passenger_load;
    }
};

#endif