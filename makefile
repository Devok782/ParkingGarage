a.exe: Vehicle.o Compact.o Truck.o ParkingGarage.o ParkingSpot.o main.o
	g++ Vehicle.o Compact.o Truck.o ParkingGarage.o ParkingSpot.o main.o

Vehicle.o: Vehicle.h Vehicle.cpp
	g++ -c -g Vehicle.cpp

Compact.o: Vehicle.h Compact.h Compact.cpp
	g++ -c -g Compact.cpp

Truck.o: Vehicle.h Truck.h Truck.cpp
	g++ -c -g Truck.cpp

ParkingGarage.o: Vehicle.h ParkingSpot.h ParkingGarage.h ParkingGarage.cpp
	g++ -c -g ParkingGarage.cpp

ParkingSpot.o: ParkingGarage.h ParkingSpot.cpp
	g++ -c -g ParkingSpot.cpp

# main.o: Vehicle.h Compact.h Truck.h ParkingGarage.h ParkingSpot.o main.cpp
# 	g++ -c -g main.cpp

main.o: Vehicle.h Compact.h Truck.h ParkingGarage.h main.cpp
	g++ -c -g main.cpp

clean:
	delete *.o a.exe