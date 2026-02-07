#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape
{
public:
    // constructor
    Shape(std::string name, std::string color);

    // accessors
    std::string GetName() const;
    std::string GetColor() const;

    // modifiers
    void SetColor(const std::string& color);
    void SetName(const std::string& name);

private:
    std::string Name;
    std::string Color;
};

#endif
