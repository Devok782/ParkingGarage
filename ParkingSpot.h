#ifndef PARKINGSPOT_H
#define PARKingSPOT_H

#include <iostream>
#include "Vehicle.h"

//enum CarType {COMPACT, TRUCK};

class ParkingSpot
{
    private:
        CarType type;
        string id;
        int level;
        int lane;
        int position;
        Vehicle* vehicle = nullptr;

    public: 
        ParkingSpot(string id, int level, int lane, int position, CarType type) :
                    id(id), level(level), lane(lane), position(position), type(type) {};
        virtual ~ParkingSpot();
        void park(Vehicle*);
        void unpark();
        CarType getType() const;
        string getTypeName() const;
        Vehicle* getVehicleReference() const;
        string getID() const;
        bool isOccupied() const;

        friend ostream& operator<<(ostream& out, const ParkingSpot& spot);
};  

#endif