#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include <memory>
#include "Vehicle.h"
class ParkingSpot
{
private:
    std::unique_ptr<Vehicle> m_vehicle;

public:
    bool isOccupied() const;
    bool parkVehicle(std::unique_ptr<Vehicle> vehicle);
    void removeVehicle();
    const Vehicle* getVehicle() const;
};
#endif

