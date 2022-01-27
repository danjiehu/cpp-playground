#include <iostream>

class Cube {
public:
    Cube(); // Custom default constructor
    Cube(const Cube& obj); // Custom copy constructor

    double getVolume();
    double getSurfaceArea();
    void setLength(double length);

private:
    double length_;
};

Cube::Cube()
{
    length_ = 1;
    std::cout << "Default constructor invoked!" << std::endl;
}

Cube::Cube(const Cube& obj)
{
    length_ = obj.length_;
    std::cout << "Copy constructor invoked!" << std::endl;
}

double Cube::getVolume()
{
    return length_ * length_ * length_;
}

double Cube::getSurfaceArea()
{
    return 6 * length_ * length_;
}

void Cube::setLength(double length)
{
    length_ = length;
}

Cube foo()
{
    Cube c;
    return c;
}

int main()
{
    Cube c2 = foo();
    return 0;
}
