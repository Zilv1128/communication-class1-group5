#ifndef __TRUCK_
#define __TRUCK_
#include "vehicle.h"
class truck : private vehicle
{
public:
    truck(int Wheels, int Weight, int Passenger_load, int Payload) : vehicle(Wheels, Weight)
    {
        passenger_load = Passenger_load;
        payload = Payload;
    }
    
    int get_wheels(void)
    {
        return wheels;
    }

    int get_weight(void)
    {
        return weight;
    }

    int get_passenger_load(void)
    {
        return passenger_load;
    }
    
    int get_payload(void)
    {
        return payload;
    }
private:
    int passenger_load;
    int payload;
};
#endif