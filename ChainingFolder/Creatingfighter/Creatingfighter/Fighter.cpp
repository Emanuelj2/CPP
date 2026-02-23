#include "Fighter.h"
#include <iostream>

//default only appears in the header file
Fighter::Fighter(std::string_view name , int hp , int damage )
	: m_name { name }, m_hp { hp }, m_damage { damage }
{}


//using chaining
Fighter& Fighter::setName(std::string_view name)
{
	m_name = name;
	return *this;
}
Fighter& Fighter::setHp(int hp)
{
	if (hp < 0)
	{
		std::cout << "invalid health\n";
		return *this;
	}

	m_hp = hp;
	return *this;
}

Fighter& Fighter::setDamage(int damage)
{
	if (damage < 0 || damage > 100)
	{
		std::cout << "invalid damage";
		return *this;
	}

	m_damage = damage;
	return *this;
}

void Fighter::print()const
{
	std::cout << "name: " << m_name
		<< "\nHp: " << m_hp
		<< "\nDamage: " << m_damage
		<< "\n\n";
}