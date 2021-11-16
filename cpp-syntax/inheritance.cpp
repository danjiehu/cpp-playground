#include <iostream>

class Entity {
public:
    float X, Y;

    void Move(float xa, float ya)
    {
        X += xa;
        Y += ya;
    }

    Entity()
        : X(0)
        , Y(0) {};
};

// class Player is now both Player and Entity type (TODO: polymorphism)
// ! Player can access all public members of Entity, but NOT the private members
// inherited type got all public members of its base type PLUS more
class Player : public Entity {
public:
    const char* Name;

    void PrintName()
    {
        std::cout << Name << std::endl;
    }
};

void PrintLocation(Entity e)
{
    std::cout << e.X << ", " << e.Y << std::endl;
}

int main()
{
    Player player;

    // ex1. Player type accessing its base type public variable and functions
    std::cout << player.X << std::endl;
    player.Move(1, 1);

    // ex2. passing Player type, even though PrintLocation() accepts Entity type
    PrintLocation(player);

    std::cin.get();
}
