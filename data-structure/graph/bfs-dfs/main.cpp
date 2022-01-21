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

// * dfs - depth first search English code *
// need: `stack` to store vertex to process in order; `seen table` to store processed vertex.
// function input: starter vertex and the graph to traverse.
// function purpose: traverse each vertex of the graph exactly once and do something with it.
// 1. declare a stack and a seen hash table for later use
// 2. push starter vertex to stack;
// 3. while stack is NOT empty, pop the front vertex of the stack and this is the vertex to process now
//  3.1 examine if the vertex should be processed by checking if it's in the seen table.
//  3.2 IF it is in the seen table, skip it.
//  3.3 IF it is NOT in the seen table, process the vertex AND add all of the vertex's children to stack
// 4. add the vertex to seen hash table; now repeat the procedure on the next vertex on stack.
// Time complexity: O(n+m)
// Space complexity: O(n)
// n is vertex count; m is edge count.

// * bfs - breath first search English code *
//
// time complexity
// space complexity

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