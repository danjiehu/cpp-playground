// this code is to demostrate
// 1. how by using virtual, we are able to invoke the derived class same-name function definition instead of the base class's
// 2. by not explicitly initializing a base class constructor, c++ will use default constructor to construct base class (it could be custom defaut)
// 3. you cannot define a base class function for the first time inside derived class
// 4. how to explicitly refer to a base class same-name function by adding namespace:: in front when inside the derived class
#include <iostream>

class flower {
private:
    int petals;

public:
    flower() { petals = 6; }; // custom constructor to initialize petals to 6
    void setPetals(int newPetals) { petals = newPetals; };
    virtual int getPetals() { return petals; }; // ! virtual is used here
    void displayPetals();
};

class daisy : public flower {
public:
    daisy() { setPetals(20); }; // daisy() calls flower() first, then calls setPetals to change reset petals to 20
    int getPetals() { return 6 * flower::getPetals(); };
    // because getPetals() have virtual keyword, this function is being redefined here, when calling d.getPetals(), it is calling this function instead of the base class function
    // we specify the invokation of base class same name function with flower::getPetals()
    // ! check how program behaves different when you remove virtual from line 15: it is not redefined in daisy and calling getPetals() in daisy class will still result in calling the base function
};

void flower::displayPetals()
{
    std::cout << getPetals() << std::endl;
}; // this function definition can NOT be defined in daisy class
// error: qualified name is not allowed

int main()
{
    flower f;
    daisy d;

    f.displayPetals();
    d.displayPetals();

    return 0;
}