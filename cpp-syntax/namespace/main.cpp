// ref: https://www.coursera.org/learn/cs-fundamentals-1/lecture/hmEtj/1-3-c-s-standard-library-std
#include <iostream>

// namespace example
// std::cout the std is the namespace to indicate that we are using the std standard library

// usually is in header file
namespace dhu {
class Cube {
public:
    void setLength(int leng);
    void printLength();

private:
    int length;
};
}

// usually is in cpp file
namespace dhu {
void Cube::setLength(int leng)
{
    length = leng;
};

void Cube::printLength()
{
    std::cout << length << std::endl;
}
}

int main()
{
    dhu::Cube c; // the dhu is the namespace
    c.setLength(2);
    c.printLength();

    return 0;
}