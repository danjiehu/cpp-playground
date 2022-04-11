#include "Shape.h"

// Cube is a inherited class from Shape
// it has two new members
//  1. constructor
//  ! inherited class cannot be constructed alone, its base class MUST be constructed first - that's why inherited class constructor uses initializer list to construct its base class first
//  1. public member function: getVolume()
//  2. private member variable: color_

class Cube : public Shape {
};