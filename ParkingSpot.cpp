#include <iostream>
#include "ParkingSpot.h"

using namespace std;

ParkingSpot::~ParkingSpot()
{

}

void ParkingSpot::park(Vehicle* vehicle)
{
    this->vehicle = vehicle;
}

void ParkingSpot::unpark()
{
    this->vehicle = nullptr;
}
CarType ParkingSpot::getType() const
{
    return type;
}

string ParkingSpot::getTypeName() const
{
    switch (type)
    {
        case COMPACT:
            return "COMPACT";
        case TRUCK:
            return "TRUCK";
        default:
            return "UNKNOWN";
    }
}

Vehicle* ParkingSpot::getVehicleReference() const
{
    return vehicle;
}

string ParkingSpot::getID() const
{
    return id;
}

bool ParkingSpot::isOccupied() const
{
    return vehicle != nullptr;
}

ostream& operator<<(ostream& out, const ParkingSpot& spot)
{
    string isOccupied = spot.isOccupied() ? spot.vehicle->getLicenseNumber() : "VACANT";
    out << spot.id << " | " << spot.getTypeName() << " | " << isOccupied;
    return out;
}