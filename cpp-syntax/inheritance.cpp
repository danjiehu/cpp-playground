#include <iostream>

class Entity {
public:
    float X, Y;

    void Move(float xa, float ya)
    {
        X += xa;
        Y += ya;
    }
};

// class Player is now both Player and Entity type (polymorphism)
// ! Player can access all public members of Entity, but NOT the private members
class Player : public Entity {
public:
    const char* Name;

    void PrintName()
    {
        std::cout << Name << std::endl;
    }
};

int main()
{
    Player player;
    player.Move(1, 1);

    std::cin.get();
}
