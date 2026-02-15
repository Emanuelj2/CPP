// OOP14.9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

class Foo
{
private:
    int m_x{};
    int m_y{};

public:

    //constructor

    //note thsy have to be in order that the variabels are in
    //Foo(int x, int y)
    //    : m_x { std::max(x, y) }, m_y { y } // here's our member initialization list
    //{
    //    std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    //}
    
    Foo(int x, int y) : m_x { x }, m_y { y }
    {
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }

    //this wont wrk since we did not initilaize the members
    /*Foo(int x, int y)
    {
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }*/

    void print() const
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ")\n";
    }
};

int main()
{
    Foo foo{ 6, 7 };
    foo.print();

    return 0;
}

