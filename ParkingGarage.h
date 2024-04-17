#ifndef PARKINGGARAGE_H
#define PARKINGGARAGE_H
#include <vector>
#include <map>

//enum CarType {COMPACT, TRUCK};

#include "Vehicle.h"
#include "ParkingSpot.h"

class ParkingGarage
{   
    private:
        map<string, ParkingSpot*> parkingSpots;
        map<string, ParkingSpot*> parkedVehicles;
        string parkingID(int level, int lane, int position);

    public:
        ParkingGarage(vector<vector<pair<int, CarType>>> parkingSpots);
        ~ParkingGarage();
        void park(Vehicle*);
        void unpark(Vehicle*);
        void checkStatus();
};

#endif