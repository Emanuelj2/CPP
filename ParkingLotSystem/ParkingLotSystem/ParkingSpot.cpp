#include "ParkingSpot.h"

bool ParkingSpot::isOccupied() const
{
    return m_vehicle != nullptr;
}

bool ParkingSpot::parkVehicle(std::unique_ptr<Vehicle> vehicle)
{
    if (isOccupied())
        return false;

    m_vehicle = std::move(vehicle);
    return true;
}

void ParkingSpot::removeVehicle()
{
    m_vehicle.reset();
}

const Vehicle* ParkingSpot::getVehicle() const
{
    return m_vehicle.get();
}