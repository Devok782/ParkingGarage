#include <iostream>
#include <vector>
#include <map>
#include <fstream>

#include "Vehicle.h"
#include "Compact.h"
#include "Truck.h"
#include "ParkingGarage.h"
//#include "ParkingSpot.h"

using namespace std;

int main()
{
    vector<vector<pair<int, CarType>>> parkingSpotsData;
    ifstream MyReadFile;
    int levels, lanes, numberOfSpots, type;
    pair<int, CarType> basePair;
    MyReadFile.open("data.txt");

    while (true)
    {
        MyReadFile >> levels;
        for (int i = 0; i < levels; ++i)
        {
            MyReadFile >> lanes;
            vector<pair<int, CarType>> rowsVector;
            for(int j = 0; j < lanes; ++j)
            {
                MyReadFile >> numberOfSpots >> type;
                basePair = make_pair(numberOfSpots, CarType(type));
                rowsVector.push_back(basePair);
            }
            parkingSpotsData.push_back(rowsVector);
        }
    }

    MyReadFile.close();

    ParkingGarage myParkingGarage(parkingSpotsData);
    myParkingGarage.checkStatus();

    return 0;
}