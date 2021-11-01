#pragma once

#include <vector>

struct Cube {
    int length;

    Cube(int leng)
        : length(leng)
    {
    }
};

struct Stack {
};

struct Game {
};

// TODO: understand visibility
std::ostream& operator<<(std::ostream& stream, const Game& other);
std::ostream& operator<<(std::ostream& stream, const Cube& other);