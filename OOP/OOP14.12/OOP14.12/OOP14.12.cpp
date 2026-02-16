// OOP14.12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <string_view>

//class Employee
//{
//private:
//    static constexpr int default_id{ 0 };
//    std::string m_name{};
//    int m_id{ default_id };
//    bool m_isManager{ false };
//
//
//    void print() const
//    {
//        std::cout << "Employee " << m_name << " created\n";
//    }
//public:
//    ////constructor
//    //Employee(std::string_view name, int id = default_id )
//    //    : m_name { name }, m_id { id }
//    //{
//    //    print();
//    //    //std::cout << "Employee " << m_name << " created\n";
//    //}
//
//    //constructor
//    Employee(std::string_view name, int id = default_id, bool manager = false)
//        : m_name{ name }, m_id{ id }, m_isManager{ manager } //the user can be a manager
//    {
//        print();
//        //std::cout << "Employee manager " << m_name << " created\n";
//
//    }
//};


class Ball
{
private:
    static constexpr double default_radius{ 10.0 };
    std::string m_color{ "balck" };
    double m_radius{ default_radius };

    void print()const
    {
        std::cout << "Ball (" << m_color << ", " << m_radius << ")\n";
    }
public:
    Ball()
    {
        print();
    }
    
    Ball(double radius)
        :m_radius { radius }
    {
        print();
    }

    Ball(std::string_view color)
        : m_color{ color }
    {
        print();
    }

    Ball(std::string_view color, double radius)
        : m_color { color }, m_radius { radius }
    {
        print();
    }

};

int main()
{
    //Employee emp1{"Emanuel", 1};
    //Employee emp2{ "Joe", 2, true };


    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };


    /*
    Ball(black, 10)
    Ball(blue, 10)
    Ball(black, 20)
    Ball(blue, 20)
    */
    return 0;
}


