#ifndef  CHARACTER_H
#define  CHARACTER_H

#include <iostream>
#include <string>

class Character
{
private:
	std::string m_name{};
	int m_age{};
	int m_hp{};
	int m_strength;

public:

	//default constructor
	Character(std::string_view name = "BOB", int age = 20, int hp = 100, int strength = 25);

	//chaining
	Character& setName(std::string_view name);
	Character& setAge(int age);
	Character& setHp(int hp);
	Character& setStrength(int strength);

	void print()const;

};

#endif // ! CHARACTER_H
