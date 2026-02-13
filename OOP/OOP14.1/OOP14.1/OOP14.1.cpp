// OOP14.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <string_view>
#include <iostream>

enum AnimalType
{
    cat,
    dog,
    chicken,
};

//constexpr allows compile-time evaluation, gives the compiler more optimization power.
//to use constexpr the function needs to have a return type.

//string_view olny reads the message and does allocate memory and cannot be midified.

/*
constexpr std::string_view animalName(AnimalType type)
{
    switch (type)
    {
    case cat:
        return "cat";
    case dog:
        return "dog";
    case chicken:
        return "chicken";
    default:
        return "";
    }
}

constexpr int numLegs(AnimalType type)
{
    switch (type)
    {
    case cat:
        return 4;
    case dog:
        return 4;
    case chicken:
        return 2;
    default:
        return 0;
    }
}
*/

struct Cat
{
    std::string_view name{ "cat" };
    int numLegs{ 4 };
};

struct Dog
{
    std::string_view name{ "dog" };
    int numLegs{ 4 };
};

struct Fish
{
    std::string_view name{ "fish" };
    int numLegs{ 0 };
};

struct Chicken
{
    std::string_view name{ "chicken" };
    int numLegs{ 2 };
};

int main()
{
    constexpr Cat animal;
    constexpr Dog animal2;
    std::cout << "A " << animal.name << " has " << animal.numLegs << " Legs\n";
    std::cout << "A " << animal2.name << " has " << animal2.numLegs << " Legs\n";


}

