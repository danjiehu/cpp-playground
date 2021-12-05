// ref-const: https://www.youtube.com/watch?v=4fJBrditnJU&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=35
// ref-mutable: https://www.youtube.com/watch?v=bP9z3H3cVMY&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb

// how to interpret `const` at different positions:
// 1. const int item_a = 3; // simple variable declaration
// meaning:
// I plan to assign value to this variable `item_a` once and only once, you can count on the intialization value to be item_a's value throughout the entirety of the program;
// or, if you want to find out item_a's value, just look at its initialization is enough

// 2. insertAtFront(const T& e){} // pass by function variable
// meaning:
// passing by reference: "I don't want you to create any copy of e, use the object value itself, for better performance; also I'm using const, so do NOT worry I will change the object accidently"
// passing by reference: "insertAtFront is not a function that will modify the parameter passed in"
// passing by const: "I don't want insertAtFront{} algo to change e's content in anyway, if I did by accident, please throw me a compiler error"
// ! in short: pass by const reference ensure max performance for operations that doesn't need to make changes to the variable (incl. class type), use it for all oeprations of such nature

// 3. int GetX() const {} // in class declaration ONLY
// meaning:
// I plan to use GetX() as a read-only function; I'm also securing future operations that wish to use GetX() is able to pass variable by const reference for max performance
// ! use const before {} for all read-only class member function

// 4. pointer related const see examples below

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
        // const int*: method returns a int pointer which deferenced value can't be modified
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
    // this is a varibale, I'm not gonna change it later
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