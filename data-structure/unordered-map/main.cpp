// this file is created to demostrate
// 1. hash table single insertion, batch insertion with vector, search, deletion, check if key exist without creating new key
// ! If you iterate over a std::unordered_map (keeping in mind that there is no particular order to the items), the individual items are the key-value pairs themselves.
// 2. Pairs: different ways to make pairs, iterate over pairs in a hash table
// ref: https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/

#include <iostream>
#include <unordered_map> // for std::unordered_map
#include <utility> // for std::pair

int main()
{

    // ====== start of example One ======
    std::unordered_map<std::string, int> umap;

    umap["someKey"] = 10;
    umap["Alice"] = 42;
    umap["anotherKey"] = 23;

    for (auto x : umap)
        std::cout << x.first << " " << x.second << std::endl;
    // 1. If you iterate over a std::unordered_map, the individual items are the key-value pairs themselves.
    // 2. Pairs
    // std::pair<std::string, int> myPair;
    // myPair.first = "Hello, this is the string element.";
    // myPair.second = 42;
    //  the std::pair template implicitly has members first and second that correspond to the elements.
    std::cout << std::endl;
    // ====== end of exmaple One ======

    // ====== start of example Two: Pairs ======
    // way 1 to make a pair
    std::pair<std::string, int> myPair;
    myPair.first = "Hello";
    myPair.second = 42;
    std::cout << myPair.first << " " << myPair.second << std::endl;

    // way 2 to make a pair
    std::pair<std::string, int> anotherPair = { "sevens", 777 };
    std::cout << anotherPair.first << " " << anotherPair.second << std::endl;

    // Some implementations of std::unordered_map actually uses std::pair internally for each key-value pair, and so some of the advanced helper functions of std::unordered_map directly deal with pairs. You can even initialize a map as a list of pairs:
    std::unordered_map<int, int> lookupTable = { { 1, 10 }, { 2, 20 }, { 3, 30 } };
    std::cout << lookupTable[2] << std::endl;
    std::unordered_map<std::string, int> lookupTable2 = { { "1", 10 }, { "2", 20 }, { "3", 30 } };
    std::cout << lookupTable2["3"] << std::endl;

    std::cout << std::endl;
    // ====== end of example Two: Pairs ======

    // ====== start of example Three: map count & size member function ======
    // count:  tell you if a key exists already or not; it only returns 0 (not found) or 1 (found).
    // size:  tells you how many different keys there are total.

    // ====== end of example Three: map count & size member function ======

    return 0;
}