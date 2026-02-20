#ifndef PARKINGLOT_H
#define PARKINGLOT_H
#include "ParkingSpot.h"
#include "Vehicle.h"
#include <vector>
class ParkingLot
{
private:
	std::vector<ParkingSpot> m_spots{};
	
public:
	
	ParkingLot(int totalSpots);

	int getOpenSpots() const;
	bool parkVehicle(std::unique_ptr<Vehicle> vehicle);
	bool removeVehicle();
	
};

#endif

