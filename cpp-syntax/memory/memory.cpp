// TODO demostrate
// 1. the `new` keyword
//  1.1 takes in an data type, so that it knows how much memory to ask for
//  1.2 find the memory big enough for this much memory
//  1.3 returns a pointer to the found memory address, which is the address where the data/object will be allocated
// 2. the `delete` keyword
// 3. object lifetime
// 4. dellocate memory automatically with smart pointers
// 5. tracking memory without any third party program
// ref: https://www.youtube.com/watch?v=sLlGEUO_EGE&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=84

#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::endl;
using std::string;

// void* operator new(size_t size)
// {
//     std::cout << "allocating " << size << "bytes" << endl;
//     return malloc(size);
// }

// void operator delete(void* memory, size_t size)
// {
//     std::cout << "freeing " << size << "bytes" << endl;
//     free(memory);
// }

class Entity {
private:
    string m_name;

public:
    Entity()
        : m_name("unknown") {};
    Entity(const string& name)
        : m_name(name) {};

    string GetName() const { return m_name; }
};

int main()
{
    int* a = new int; // this line means, please return me a int pointer, stored in variable `a`, `a` points to a heap memory of 4 bytes (int size is 4)
    int* arr = new int[3]; // 200 bytes, one int is 4 bytes
    int* b = a;

    // Entity* e = new Entity(); // Entity() is the constructor
    // Entity* e2 = new Entity[3]; // this is an array of entity, size entity * 50

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    delete a;
    a = nullptr;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    delete[] arr;
    // delete e;
    // delete[] e2;

    return 0;
}