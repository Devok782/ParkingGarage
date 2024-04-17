#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle
{
    private:
        const CarType type = CarType::TRUCK;

    public:
        Truck();
        Truck(int, int, string);
        virtual ~Truck();
        virtual CarType getType() const;
};

#endif