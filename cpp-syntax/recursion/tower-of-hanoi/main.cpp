
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

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

    void move(std::vector<Cube>& start, std::vector<Cube>& end)
    {
        Cube& top_cube = start.back();
        start.pop_back();
        end.push_back(top_cube);
    }

    void solve()
    {
    }
};

// overload  << with printing cube
std::ostream& operator<<(std::ostream& stream, const Cube& cube)
{
    stream << cube.m_length;
    return stream;
};

// overload << with printing game
std::ostream& operator<<(std::ostream& stream, const Game& game)
{
    stream << "[source] ";
    for (int i = 0; i < game.stack_source.size(); i++) {
        stream << game.stack_source[i] << " ";
    }
    stream << endl;

    stream << "[spare] ";
    for (int i = 0; i < game.stack_spare.size(); i++) {
        stream << game.stack_spare[i] << " ";
    }
    stream << endl;

    stream << "[target] ";
    for (int i = 0; i < game.stack_target.size(); i++) {
        stream << game.stack_target[i] << " ";
    }

    return stream;
};

int main()
{
    Game g;

    cout << "initial game state: " << endl;
    cout << g << endl;

    g.move(g.stack_source, g.stack_target);
    cout << "testing move: " << endl;
    cout << g << endl;

    return 0;
};
