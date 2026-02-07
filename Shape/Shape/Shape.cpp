#include "Shape.h"

// constructor
Shape::Shape(std::string name, std::string color)
    : Name(name), Color(color) {
}

// accessors
std::string Shape::GetName() const
{
    return Name;
}

std::string Shape::GetColor() const
{
    return Color;
}

// modifiers
void Shape::SetColor(const std::string& newColor)
{
    Color = newColor;
}

void Shape::SetName(const std::string& newName)
{
    Name = newName;
}
