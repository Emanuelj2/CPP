#include "Shape.h"
#include <iostream>

int main()
{
    Shape s("Circle", "Red");

    std::cout << s.GetName() << " - " << s.GetColor() << std::endl;
    std::cout << __cplusplus << std::endl;
    return 0;
}
