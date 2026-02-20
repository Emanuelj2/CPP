#include <iostream>
#include <memory>
#include "ParkingLot.h"

int main()
{
    ParkingLot lot(3);

    auto car = std::make_unique<Vehicle>("Red", 4, 4, VehicleType::Car);
    auto truck = std::make_unique<Vehicle>("Blue", 2, 6, VehicleType::Truck);

    lot.parkVehicle(std::move(car));
    lot.parkVehicle(std::move(truck));

    std::cout << "Open spots: " << lot.getOpenSpots() << "\n";

    return 0;
}