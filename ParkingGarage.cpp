#include <iostream>
#include "ParkingGarage.h"

using namespace std;

ParkingGarage::ParkingGarage(vector<vector<pair<int, CarType>>> parkingSpots)
{
    ParkingSpot* spot;
    string id;
    for(int level = 0; level < parkingSpots.size(); ++level)
    {
        for(int lane = 0; lane < parkingSpots.size(); ++lane)
        {
            for(int position = 0; position < parkingSpots[level][lane].first; ++position)
            {
                id = parkingID(level + 1, lane + 1, position + 1);
                spot = new ParkingSpot(id, level + 1, lane + 1, position + 1, parkingSpots[level][lane].second);
                this->parkingSpots[id] = spot;
            }
        }
    }
}

ParkingGarage::~ParkingGarage()
{
    for (auto iter = parkingSpots.begin(); iter != parkingSpots.end(); iter++)
    {
        delete (*iter).second;
    }
}

void ParkingGarage::park(Vehicle* vehicle)
{
    ParkingSpot *spot = nullptr;
    auto iter = parkingSpots.begin();
    while (iter != parkingSpots.end())
    {
        spot = iter->second;
        if (!spot->isOccupied())
        {
            spot->park(vehicle);
            parkedVehicles[vehicle->getLicenseNumber()] = spot;
            break;
        }
        iter++;
    }
    if (iter == parkingSpots.end())
    {
        throw "No parking space available for " + vehicle->getLicenseNumber();
    }
}

void ParkingGarage::unpark(Vehicle* vehicle)
{
    auto iter = parkedVehicles.find(vehicle->getLicenseNumber());
    if(iter == parkedVehicles.end())
    {
        throw "Vehicle has been unparked";
        return;
    }
    iter->second->unpark();
    parkedVehicles.erase(iter);
}

string ParkingGarage::parkingID(int level, int lane, int position)
{
    string result = "";
    result += (level >= 10) ? to_string (level): '0' + to_string(level);
    result += (lane >= 10) ? to_string (lane): '0' + to_string(lane);
    result += (position >= 10) ? to_string (position): '0' + to_string(position);
    return result;
}

void ParkingGarage::checkStatus()
{
    auto iter = parkingSpots.begin();
    while(iter != parkingSpots.end())
    {
        cout << (*(*iter).second) << endl;
        iter++;
    }
}