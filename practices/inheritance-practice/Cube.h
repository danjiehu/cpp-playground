#include "Shape.h"
#include <string>

//  ! derived class only use all public members of the base class, NOT the private members

// Cube is a inherited class from Shape
// it has two new members
//  1. constructor
//  ! inherited class cannot be constructed alone, its base class MUST be constructed first - that's why inherited class constructor uses initializer list to construct its base class first
//  1. public member function: getVolume()
//  2. private member variable: color_

class Cube : public Shape { // denote that Cube is a inherited class of Shape, always public
public:
    Cube(std::string color, double width);
    double getVolume() const;

private:
    std::string color_;
};

Cube::Cube(std::string color, double width)
    : Shape(width)
    , color_(color) {};
// this syntax is also ok
// Cube::Cube(std::string color, double width)
//     : Shape(width) // ! this is calling the base class constructor
// {
//     color_ = color; // this is unique to the Cube class
// };

double Cube::getVolume() const
{
    double width = getWidth();
    return width * width * width;
};

// double Cube::getVolume() const
// {
//     return width_ * width_ * width_; // ! error: 'width_' is a private member of 'Shape'
// };