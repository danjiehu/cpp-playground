#pragma once

class Shape {
public:
    Shape();
    Shape(double width);

    double getWidth() const; // const here means that this function does NOT modify any class member variables

private:
    double width_;
};

Shape::Shape()
    : Shape(1) {};

Shape::Shape(double width)
    : width_(width) {};

double Shape::getWidth() const
{
    return width_;
};