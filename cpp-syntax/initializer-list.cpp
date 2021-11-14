/*
Member Initializer Lists 
- always use initializer list over conventional constructor 

ref https://www.youtube.com/watch?v=1nfuYMXjZsA

class ScoreCardA with conventional constructor - commented out
class ScoreCardB with constructor initializer list
*/

#include <iostream>
#include <string>

class ScoreCardB {
private:
    std::string m_name;
    int m_score;

public:
    ScoreCardB()
        : m_name("unknown")
        , m_score(0)
    // in initializer list, make sure it's the SAME ORDER as when the member variables are declared
    {
    }

    ScoreCardB(std::string name, int score)
        : m_name(name)
        , m_score(score + score)
    {
    }

    std::string GetContent()
    {
        std::string score_str = std::to_string(m_score);
        std::string content = m_name + ", " + score_str;
        return content;
    }
};

int main()
{
    ScoreCardB c0;
    std::cout << c0.GetContent() << std::endl;

    ScoreCardB c1("dhu", 100);
    std::cout << c1.GetContent() << std::endl;

    return 0;
}

// class ScoreCardA {
// private:
//     std::string m_name;
//     int m_score;

// public:
//     ScoreCardA()
//     {
//         m_name = "unknown";
//         m_score = 0;
//     }

//     ScoreCardA(const std::string& name, int score)
//     {
//         m_name = name;
//         m_score = score;
//     }

//     std::string GetContent()
//     {
//         std::string score_str = std::to_string(m_score);
//         std::string content = m_name + ", " + score_str;
//         return content;
//     }
// };

// int main()
// {
//     ScoreCardA c0;
//     std::cout << c0.GetContent() << std::endl;

//     ScoreCardA c1("dhu", 100);
//     std::cout << c1.GetContent() << std::endl;

//     return 0;
// }