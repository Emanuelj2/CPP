#ifndef FIGHTER_H
#define FIGHTER_H

#include <string>

class Fighter
{
private:
	std::string m_name{};
	int m_hp{};
	int m_damage{};

public:

	//default values only appear in the hader file
	Fighter(std::string_view name = "BOB", int hp = 100, int damage = 10);

	Fighter& setName(std::string_view name);
	Fighter& setHp(int hp);
	Fighter& setDamage(int damage);

	void print()const;
};

#endif