#include "Vehicle.h"

Vehicle::Vehicle()
{   
    arrivalTime = 0;
    parkedTime = 0;
    licenseNumber = "000-000";
}

Vehicle::Vehicle(int arrived, int parked, string numbers)
{
    arrivalTime = arrived;
    parkedTime = parked;
    licenseNumber = numbers;
}

Vehicle::~Vehicle()
{

}

int Vehicle::getArrivalTime() const
{
    return arrivalTime;
}

int Vehicle::getParkedTime() const
{
    return parkedTime;
}

string Vehicle::getLicenseNumber() const
{
    return licenseNumber;
}