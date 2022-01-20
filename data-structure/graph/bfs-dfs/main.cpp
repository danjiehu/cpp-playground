// * demo purpose *
// ref: https://www.youtube.com/watch?v=TIbUeeksXcI
// 1. demostrate how to do bfs and dfs on a graph data structure
// 2. dfs: with stack, go deep fast
// 3. bfs: with queue, explore data level by level
// 4. using a hash table to build the same graph presented in the Youtube Video; where key is the vertex, and value is the vertex's adjacent edges.
// graph visual:
//    (G)--------(B)--------
//     |          |        |
//    (F)---(E)--(A)------(C)
//     |      \   /        ｜
//    (H)------(D)----------

// * bfs - breath first search English code *
// * dfs - depth first search English code *

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility> // for std::pair

struct Graph {
    // using std::pair<char, char> = charPair;
    // using neighborSet = std::unorder_set<charPair>;
    // std::unordered_map<char, neighborSet> adjacencyMap;
    // TODO: learn how to use customized type i.e. pairs on hash table in order to create a adjacency map
};

int main()
{
    return 0;
}