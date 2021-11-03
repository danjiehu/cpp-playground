
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

// overload  << with printing cube
std::ostream& operator<<(std::ostream& stream, const Cube& cube)
{
    stream << cube.m_length;
    return stream;
};

struct Game {
    std::vector<Cube> stack_source;
    std::vector<Cube> stack_spare;
    std::vector<Cube> stack_target;
    int n;

    // game default constructor
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

        n = stack_source.size();
    }

    void move(std::vector<Cube>& source, std::vector<Cube>& target)
    {
        Cube& top_cube = source.back();
        source.pop_back();
        target.push_back(top_cube);
        cout << *this << endl;
    }

    void solve(int n, std::vector<Cube>& source, std::vector<Cube>& spare, std::vector<Cube>& target)
    {
        if (n == 1) {
            move(source, target);
        } else {
            solve(n - 1, source, target, spare);
            solve(1, source, spare, target);
            solve(n - 1, spare, source, target);
        }
    }

    // overload << with printing game
    //! tested: if we define this function outside of Game scope, we cannot call it within Game
    friend std::ostream& operator<<(std::ostream& stream, const Game& game)
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
};

int main()
{
    Game g;

    cout << "initial game state: " << endl;
    cout << g << endl;

    g.solve(g.stack_source.size(), g.stack_source, g.stack_spare, g.stack_target);

    return 0;
};
