#include "Vehicle.h"
#include "iostream"

Vehicle::Vehicle(std::string_view color, int doors, int tires, VehicleType type)
	: m_color{ color }, m_doors{ doors }, m_tires{ tires }, m_type { type }
{
}

//getters
std::string Vehicle::getColor()const
{
	return m_color;
}

int Vehicle::getDoors()const
{
	return m_doors;
}

int Vehicle::getTires()const
{
	return m_tires;
}

VehicleType Vehicle::getType() const 
{
	return m_type;
}

//setters
void Vehicle::setColor(std::string color)
{
	if (color == "")
	{
		std::cout << "no color\n";
	}
	m_color = color;
}
void Vehicle::setDoors(int doors)
{
	m_doors = doors;
}
void Vehicle::setTires(int tires)
{
	if (tires == 0)
	{
		std::cout << "impossible\n";
		return;
	}
	m_tires = tires;
}