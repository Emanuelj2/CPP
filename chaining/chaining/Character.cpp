#include "Character.h"

Character::Character(std::string_view name = "BOB", int age = 20, int hp = 100, int strength = 25)
	: m_name{ name }, m_age{ age }, m_hp{ hp }, m_strength{ strength }
{
}

//chaining
Character& Character::setName(std::string_view name)
{
	m_name = name;
	return *this;
}
Character& Character::setAge(int age)
{
	m_age = age;
	return *this;
}
Character& Character::setHp(int hp)
{
	m_hp = hp;
	return *this;
}
Character& Character::setStrength(int strength)
{
	m_strength = strength;
	return *this;
}

void Character::print()const
{
	std::cout << "Name: " << m_name
		<< " Age: " << m_age
		<< " HP: " << m_hp
		<< " STR: " << m_strength << "\n";
}