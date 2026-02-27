#include <iostream>
#include <string>
#include <random>


//random number genorator
int RandomNumber(int min, int max)
{
    static std::mt19937 gen(std::random_device{}()); //engin that produces raw random number
    std::uniform_int_distribution<int> dist(min, max); //distribution controls range/type
    return dist(gen);
}

//note is the enum is not nested (in the class) the syntax is "enum class name"
//otherwise "enum name"


class Monster
{
public:
    enum MonsterType
    {
        Dragon,
        Goblin,
        Ogre,
        Orc,
        Skeleton,
        Troll,
        Vampire,
        Zombie,
        maxMonsterTypes,
    };

private:
    MonsterType m_type{};
    std::string m_name{"???"};
    std::string m_roar{"???"};
    int m_hitPoints{};

public:

    //consttructor
    Monster(MonsterType type, std::string_view name, std::string_view roar, int hitPoints)
        : m_type{ type }, m_name{ name }, m_roar{ roar }, m_hitPoints{ hitPoints }
    {}

    constexpr std::string_view getTypeString()const
    {
        switch (m_type)
        {
        case Dragon:
            return "dragon";
        case Goblin:
            return "goblin";
        case Ogre:
            return "ogre";
        case Orc:
            return "orc";
        case Skeleton:
            return "skeleton";
        case Troll:
            return "troll";
        case Vampire:
            return "vampire";
        case Zombie:
            return "zombie";
        default:
            return "???";
                
        }
    }

    void print() const
    {
        if (m_hitPoints <= 0)
        {
            std::cout << m_name << " the " << getTypeString() << " is dead "  << std::endl;
        }
        else
        {
            std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << std::endl;
        }
        
    }

};

namespace MonsterGenerator
{
    

    std::string_view getName(int num)
    {
        switch (num)
        {
        case 0:  
            return "Blarg";
        case 1:  
            return "Moog";
        case 2:  
            return "Pksh";
        case 3:  
            return "Tyrn";
        case 4:  
            return "Mort";
        case 5:  
            return "Hans";
        default: 
            return "???";
        }
    }

    std::string_view getRoar(int num)
    {
        switch (num)
        {
        case 0:  
            return "*ROAR*";
        case 1:  
            return "*peep*";
        case 2:  
            return "*squeal*";
        case 3:  
            return "*whine*";
        case 4:  
            return "*growl*";
        case 5:  
            return "*burp*";
        default: 
            return "???";

        }
    }

    Monster generate()
    {
        return Monster{ static_cast<Monster::MonsterType>(RandomNumber(0, Monster::maxMonsterTypes - 1)),
            getName(RandomNumber(0, 5)),
            getRoar(RandomNumber(0, 5)),
            RandomNumber(0, 100)};
    }
}

int main()
{
    Monster Skeleton{ Monster::Skeleton, "Bones", "*rattle*", 4 };
    Skeleton.print();

    Monster Vampire{ Monster::Vampire, "Nibblez", "*hiss*", 0 };
    Vampire.print();

    Monster m{ MonsterGenerator::generate() };
    m.print();
    
}
