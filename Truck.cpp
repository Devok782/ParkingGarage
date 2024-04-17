#include "Truck.h"

Truck::Truck(int arrived, int parked, string numbers) : Vehicle(arrived, parked, numbers)
{

}

Truck::~Truck()
{

}

CarType Truck::getType() const
{
    return type;
}