// * demo purpose *
// ref: https://www.youtube.com/watch?v=TIbUeeksXcI
// 1. demostrate how to do bfs and dfs on a graph data structure
// 2. dfs: with stack, go deep fast
// 3. bfs: with queue, explore data level by level

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
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using IntPair = std::pair<int, int>;

struct Graph {
    int num_edges;
    int num_nodes;
    std::vector<int> vertexList; // using int to represent vertex
    std::vector<IntPair> edgeList; // using int pair to represent each edge

    // print the graph by printing each edge
    void print()
    {
        for (auto edge : edgeList) {
            std::cout << edge.first << " " << edge.second << std::endl;
        }
    }

    void dfs(int starter_vertex);
    void bfs(int starter_vertex);
};

void Graph::dfs(int starter_vertex)
{
    std::stack<int> node_to_traverse;
    std::unordered_set<int> seen;

    node_to_traverse.push(starter_vertex);

    std::cout << "depth first traversal: ";
    while (!node_to_traverse.empty()) {

        int curr = node_to_traverse.top();
        node_to_traverse.pop();

        if (!seen.count(curr)) {
            seen.insert(curr);
            std::cout << curr << " ";

            for (auto edge : edgeList) {
                if (edge.first == curr) {
                    node_to_traverse.push(edge.second);
                } else if (edge.second == curr) {
                    node_to_traverse.push(edge.first);
                }
            }
        }
    }
    std::cout << std::endl;
}

void Graph::bfs(int starter_vertex)
{
    std::queue<int> node_to_traverse;
    std::unordered_set<int> seen;

    node_to_traverse.push(starter_vertex);

    std::cout << "breadth first traversal: ";
    while (!node_to_traverse.empty()) {

        int curr = node_to_traverse.front();
        node_to_traverse.pop();

        if (!seen.count(curr)) {
            // if not seen, add it to seen then process it
            seen.insert(curr);
            std::cout << curr << " ";

            // if not seen, add its children
            for (auto edge : edgeList) {
                if (edge.first == curr) {
                    node_to_traverse.push(edge.second);
                } else if (edge.second == curr) {
                    node_to_traverse.push(edge.first);
                }
            }
        }
    }
    std::cout << std::endl;
}

int main()
{
    Graph g;
    // recreating this graph
    // (0)-(1)-(2)-(3)-(4)-(5)-(6)-(7)
    //              |               |
    //               ---------------
    g.num_edges = 8;
    g.num_nodes = 8;
    // g's vertex list
    for (int i = 0; i < g.num_nodes; i++) {
        g.vertexList.push_back(i);
    }
    // g's edge list
    g.edgeList.push_back({ 0, 1 });
    g.edgeList.push_back({ 1, 2 });
    g.edgeList.push_back({ 2, 3 });
    g.edgeList.push_back({ 3, 4 });
    g.edgeList.push_back({ 4, 5 });
    g.edgeList.push_back({ 5, 6 });
    g.edgeList.push_back({ 6, 7 });
    g.edgeList.push_back({ 3, 7 });
    // g.print();
    // end of creating the graph

    g.dfs(3);
    g.bfs(3);

    return 0;
}