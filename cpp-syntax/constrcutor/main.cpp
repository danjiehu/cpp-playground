// demo contains
// 1. examples of copy constructor
// 2. examples of assignment operator

#include <iostream>

class Cube {
public:
    double getVolume();
    void setLength(double length);

private:
    double length_;
};

double Cube::getVolume()
{
    return length_ * length_ * length_;
}

int main()
{
    return 0;
}