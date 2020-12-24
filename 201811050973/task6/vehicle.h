#ifndef __VEHICLE_
#define __VEHICLE_

class vehicle
{
public:
    vehicle(int Wheels = 0, int Weight = 0)
    {
        wheels = Wheels;
        weight = Weight;
    }

    int get_wheels(void)
    {
        return wheels;
    }

    int get_weight(void)
    {
        return weight;
    }
protected:
    int wheels;
    int weight;
};

#endif