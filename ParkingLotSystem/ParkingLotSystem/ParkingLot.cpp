#include "ParkingLot.h"

ParkingLot::ParkingLot(int totalSpots) 
{
	m_spots.resize(totalSpots);
}

int ParkingLot::getOpenSpots() const
{
	int openSpots = 0;

	for(const auto& spot : m_spots)
	{
		if (!spot.isOccupied())
		{
			openSpots++;
		}
	}
	return openSpots;
}

bool ParkingLot::parkVehicle(std::unique_ptr<Vehicle> vehicle)
{
	for (auto& spot : m_spots)
	{
		if (!spot.isOccupied())
		{
			return spot.parkVehicle(std::move(vehicle));
		}
	}

	return false;
}

bool ParkingLot::removeVehicle()
{
	for (auto& spot : m_spots)
	{
		if (spot.isOccupied())
		{
			spot.removeVehicle();
			return true;
		}
	}
	return false;
}