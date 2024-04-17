#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

using namespace std;

enum CarType {COMPACT, TRUCK};

class Vehicle
{
    private:  
        int arrivalTime;
        int parkedTime;
        string licenseNumber;

    public: 
        Vehicle();
        Vehicle(int, int, string);
        virtual ~Vehicle();
        int getArrivalTime() const;
        int getParkedTime() const;
        string getLicenseNumber() const;
        virtual CarType getType() const = 0;
};

#endif