
#include <iostream>
#include <vector>

struct Cube {
    int m_length;

    Cube(int leng)
        : m_length(leng)
    {
    }
};

struct Game {
    std::vector<Cube> stack_source;
    std::vector<Cube> stack_spare;
    std::vector<Cube> stack_target;

    Game()
    {
        Cube c1(1);
        Cube c2(2);
        Cube c3(3);
        Cube c4(4);
        stack_source.push_back(c4);
        stack_source.push_back(c3);
        stack_source.push_back(c2);
        stack_source.push_back(c1);
    };
};

std::ostream& operator<<(std::ostream& stream, const Cube& cube)
{
    stream << cube.m_length;
    return stream;
};

void print(std::vector<Cube> const& a)
{
    std::cout << "The vector elements are : ";

    for (int i = 0; i < a.size(); i++)
        std::cout << a[i] << ' ';
}

// std::ostream& operator<<(std::ostream& stream, const Game& game)
// {
//     for (int i = 0; i < game.stack_source.size(); i++) {
//         stream << game.stack_source[i];
//     }

//     return stream;
// };

int main()
{
    Game g;

    std::cout << "initial game state: " << std::endl;
    print(g.stack_source);

    return 0;
};
