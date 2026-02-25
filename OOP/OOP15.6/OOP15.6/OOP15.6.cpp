#include <iostream>
#include <random>
#include <chrono>

//int generateId()
//{
//    static int s_id{1};
//    return s_id++;
//}

//class Something
//{
//private:
//    //BEST PRACTICE
//    //Make your static members inline or constexpr so they can be initialized inside the class definition.
//    static inline int s_idGenorator{1};
//    int m_id{};
//public:
//    Something(): m_id{ s_idGenorator++ }
//    {
//    }
//
//    int getID()const
//    {
//        return m_id;
//    }
//};

//BEST PRACTICE
//Access static members using the class name and the scope resolution operator (::)
//int Something::s_value{ 1 };


//class GenerateId
//{
//private:
//    static inline int s_id{};
//
//public:
//    static int getId();
//};
//
//int GenerateId::getId()
//{
//    return ++s_id;
//}


//--------make the following static
namespace Random
{
    static std::mt19937 generate()
    {
        std::random_device rd{};

        //create seed_seq with high-res clock and 7 random numbers from random_device
        std::seed_seq ss
        {
            static_cast<std::seed_seq::result_type>
            (std::chrono::steady_clock::now().time_since_epoch().count()),
            rd(), rd(), rd(), rd(), rd(), rd(), rd()
        };

        return std::mt19937{ ss };
    }
    static inline std::mt19937 mt{ generate() }; // generates a seeded std::mt19937 and copies it into our global object

    // Generate a random int between [min, max] (inclusive)
    static int get(int min, int max)
    {
        return std::uniform_int_distribution{ min, max }(mt);
    }
}

int main()
{
    /*std::cout << generateId() << "\n";
    std::cout << generateId() << "\n";
    std::cout << generateId() << "\n";*/

    /*Something::s_value = 2;
    std::cout << Something::s_value << "\n";*/

    /*Something first{};
    Something second{};
    Something third{};

    std::cout << first.getID() << '\n';
    std::cout << second.getID() << '\n';
    std::cout << third.getID() << '\n';*/

    /*for (int coutn = 0; coutn < 5; coutn++)
    {
        std::cout << "The next ID is: " << GenerateId::getId() << '\n';
    }*/

    // Print a bunch of random numbers
    for (int count{ 1 }; count <= 10; ++count)
        std::cout << Random::get(1, 6) << '\t';

    std::cout << '\n';

    return 0;
}
