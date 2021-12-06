// used by pointer to access elements in structs, unions and classes with fewer syntax
// syntax: (pointer_name)->(variable name)
// this variable could also be a pointer

#include <iostream>
#include <string>

using std::cout;
using std::endl;

struct student {
    student(const std::string& n)
        : name(n)
        , age(0)
        , grade(0)
    {
    }

    std::string name;
    int age;
    int grade;
};

int main()
{
    // creating an student obj on heap
    student* dhu = new student("dhu");
    dhu->age = 22;
    dhu->grade = 7;

    return 0;
}