#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <string_view>

enum class VehicleType
{
	Car,
	Truck,
	Motorcycle
};

class Vehicle
{
private:
	std::string m_color{};
	int m_doors{};
	int m_tires{};
	VehicleType m_type{};

public:
	
	Vehicle(std::string_view color, int doors, int tires, VehicleType type);

	//getters
	std::string getColor()const;
	int getDoors()const;
	int getTires()const;
	VehicleType getType() const;

	//setters
	void setColor(std::string color);
	void setDoors(int doors);
	void setTires(int tires);
	

};
#endif