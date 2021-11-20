// ref-const: https://www.youtube.com/watch?v=4fJBrditnJU&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=35
// ref-mutable: https://www.youtube.com/watch?v=bP9z3H3cVMY&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb
#include <iostream>
#include <string>

using std::cout;
using std::endl;

// const-class-method ex. 5:
class entity {
private:
    int m_X, *m_Y;
    // int* m_X, m_Y: m_X is a pointer and m_Y is still an interger
    // int* m_X, *m_Y: both is pointer
    mutable int m_DebugCount = 0; //! mutatble means: the const methods inside the class are allowed to modify this variable

public:
    // *ex. 3 const-class-method
    int GetX() const
    // const here means that this method GetX() can NOT modify any class members
    // use it for all "read-only" methods/getters
    {
        // !error: m_X = 2;
        m_DebugCount++;
        return m_X;
    }

    // *ex. 3 const-class-method
    const int* const GetY() const
    {
        // const int*: method returns a int pointer which content can't be modified
        // const: this pointer's pointed address also can't be modified
        // GetY() const{}: promise not to modify the class itself
        return m_Y;
    }

    // *ex. 3 const-class-method
    void SetX(int x) { m_X = x; } // setters need to write to the class, CAN'T use const before {}

    // *ex. 4 mutable
    void printEntityX(const entity& e)
    {
        cout << "m_X: " << e.GetX() << endl;
        // if previousy `int GetX(){}` without const before {}, // !error: because GetX() doesn't promise not to modify the class
        cout << "m_DebugCount: " << m_DebugCount << endl;
    }
};

int main()
{
    //*ex. 4 mutable: m_DebugCount testing
    entity e1;
    e1.printEntityX(e1);
    e1.printEntityX(e1);

    //*ex. 1: const-variable
    //this is a varibale, I'm not gonna change it later
    const int MAX_AGE = 90;
    // !error: MAX_AGE = 91;

    //*ex. 2.1 const-pointer: can't modify the `*ptr` content of pointer syntax
    const int* a = new int;
    // equivalent to `int const*  b = new int;` (as long as it's before the asterisk)
    // !error: *a =2;
    a = &MAX_AGE;
    cout << "*a: " << *a << endl;

    //*ex. 2.2 const-pointer: can't modify `ptr` pointed address syntax
    int* const b = new int;
    // !error: b = &MAX_AGE;
    *b = 1;
    cout << "*b: " << *b << endl;
    *b = 2;
    cout << "*b: " << *b << endl;

    //*ex. 2.3 const-pointer
    const int* const c = new int;
    cout << "c" << c << endl;
    // !error: c = &MAX_AGE;
    // !error: *c = 1;

    return 0;
}