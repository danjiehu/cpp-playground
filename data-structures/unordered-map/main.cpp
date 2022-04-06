// this file is created to demostrate
// 1. hash table single insertion, batch insertion with vector, search, deletion, check if key exist without creating new key
// ! If you iterate over a std::unordered_map (keeping in mind that there is no particular order to the items), the individual items are the key-value pairs themselves.
// 2. Pairs: different ways to make pairs, iterate over pairs in a hash table
// ref: https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/

#include <iostream>
#include <unordered_map> // for std::unordered_map
#include <utility> // for std::pair
#include <vector>

// for example SIX
using StringIntMap = std::unordered_map<std::string, int>;
using StringVec = std::vector<std::string>;
StringIntMap makeWordCounts(const StringVec& words)
{
    StringIntMap wordcount_map;

    for (auto word : words) {
        if (wordcount_map.count(word)) {
            // if word already exist as a key
            wordcount_map.at(word) += 1;
        } else {
            // if word doesn't exist
            wordcount_map[word] = 1;
        }
    }
    return wordcount_map;
}

int main()
{

    // ====== start of example: basics ======
    std::unordered_map<std::string, int> umap;

    umap["someKey"] = 10;
    umap["Alice"] = 42;
    umap["anotherKey"] = 23;
    umap["Alice"] = 43; // changed the previous key value
    // [] can only be used on non-const instances of a map, it returns a direct reference to the mapped value item that it found AND if the key item doesn’t exist, it will be created as soon as you refer to it with [], and initialized with some default value.
    // check count() & at() if you don't wanna accidently modify the hash table

    for (auto x : umap)
        std::cout << x.first << " " << x.second << std::endl;
    // 1. If you iterate over a std::unordered_map, the individual items are the key-value pairs themselves.
    // 2. Pairs
    // std::pair<std::string, int> myPair;
    // myPair.first = "Hello, this is the string element.";
    // myPair.second = 42;
    //  the std::pair template implicitly has members first and second that correspond to the elements.

    std::cout << "EXAMPLE ONE END"
              << "\n\n";
    // ====== end of exmaple: basics ======

    // ====== start of example: Pairs ======
    // way 1 to make a pair
    std::pair<std::string, int> myPair;
    myPair.first = "Hello";
    myPair.second = 42;
    std::cout << myPair.first << " " << myPair.second << std::endl;

    // way 2 to make a pair
    std::pair<std::string, int> anotherPair = { "sevens", 777 };
    std::cout << anotherPair.first << " " << anotherPair.second << std::endl;

    // ways to make a pair summarize
    // in pract we usually shorten std::pair<int, int> with IntPair, the syntax for that is,
    // using IntPair = std::pair<int,int>;
    std::pair<int, int> intPair1 = std::pair<int, int>(1, 2);
    std::pair<int, int> intPair2 = std::make_pair(1, 2);
    auto intPair3 = std::pair<int, int>(1, 2);
    std::pair<int, int> intPair4 = { 1, 2 };

    // Some implementations of std::unordered_map actually uses std::pair internally for each key-value pair, and so some of the advanced helper functions of std::unordered_map directly deal with pairs. You can even initialize a map as a list of pairs:
    std::unordered_map<int, int> lookupTable = { { 1, 10 }, { 2, 20 }, { 3, 30 } };
    std::cout << lookupTable[2] << std::endl;
    std::unordered_map<std::string, int> lookupTable2 = { { "1", 10 }, { "2", 20 }, { "3", 30 } };
    std::cout << lookupTable2["3"] << std::endl;

    std::cout << "EXAMPLE TWO END"
              << "\n\n";
    // ====== end of example: Pairs ======

    // ====== start of example: map lookup count() & size() member function ======
    // count(): Tells you if a key exists already or not; it only returns 0 (not found) or 1 (found).
    // size(): Tells you how many different keys there are total.

    std::cout << "Map size before: " << lookupTable.size() << std::endl;
    if (lookupTable.count(4)) {
        std::cout << "Found the associated key value" << lookupTable[4] << std::endl;
    } else {
        std::cout << "Key 4 doesn't exist. The map is unchanged." << std::endl;
    }
    std::cout << "Map size after: " << lookupTable.size() << std::endl;

    std::cout << "EXAMPLE THREE END"
              << "\n\n";
    // ====== end of example: map lookup count() & size() member function ======

    // ====== start of example: map lookup at(), find() & end() member function ======
    // at(): Search for a given key and return a reference like [], but at will throw an exception if the key is not found, instead of modifying the map. For this reason, at() can be used on const map objects when [] cannot.
    // using umap from before
    std::cout << "umap size before: " << umap.size() << std::endl;
    std::cout << "Found key value: " << umap.at("Alice") << std::endl; // 42
    // std::cout << umap.at("wonderland") << std::endl; // throws exception and terminate the program
    std::cout << "umap size after: " << umap.size() << std::endl;

    // find(): Which returns an iterator type, which are used to point at memory addresses of STL containers. The iterator points to a key-value pair found, or otherwise to the map’s end iterator given by end(). This is more cumbersome than using at, but it depends on how good you are at avoiding exceptions.
    std::cout << "umap size before: " << umap.size() << std::endl;
    if (umap.find("Alice") == umap.end()) // this is the syntax to express if something is not found
        std::cout << "Key not found \n";
    else
        std::cout << "Found key value: " << umap.at("Alice") << "\n";
    // ! for checking, always use at() in case accidentally adds to hash table
    std::cout << "umap size after: " << umap.size() << std::endl;

    // end(), begin() iterators:
    // Iterators are used to point at the memory addresses of STL containers. They are primarily used in sequence of numbers, characters etc. They reduce the complexity and execution time of program.
    // begin(): This function is used to return the beginning position of the container.
    // end(): This function is used to return the after end position of the container.
    // std::cout << umap.end() << std::endl; // !error: invalid operands to binary expression, cannot cout
    std::cout << "\n"
              << (*umap.begin()).first << std::endl;
    std::cout << umap.begin()->first << std::endl; // store the key part
    std::cout << umap.begin()->second << std::endl; // store the value part

    //  iterating over all value of umap
    std::unordered_map<std::string, int>::iterator itr; // declaring an unordered map iterator type variable `itr`
    std::cout << "umap element iteration with range-based for loop and iterator: \n";
    for (itr = umap.begin(); itr != umap.end(); itr++) {
        // itr works as a pointer to pair<string, double>
        // type itr->first stores the key part  and
        // itr->second stores the value part
        std::cout << itr->first << "  " << itr->second << std::endl;
    }

    std::cout << "EXAMPLE FOUR END"
              << "\n\n";
    // ====== end of example: map lookup at(), find() & end() member function ======

    // ====== start of example: map erase() ======
    std::cout << "umap size before erase: " << umap.size() << std::endl;
    umap.erase("Alice");
    for (auto x : umap) {
        std::cout << x.first << " " << x.second << std::endl;
    }
    std::cout << "umap size after erase: " << umap.size() << std::endl;

    std::cout << "EXAMPLE FIVE END"
              << "\n\n";
    // ====== end of example: map erase() ======

    // ====== start of example: map operations with vector ======
    const std::vector<std::string>& AliceVec = { "where", "is", "alice", "wonderland", "alice", "is", "great" };

    StringIntMap AliceMap = makeWordCounts(AliceVec);
    for (auto x : AliceMap) {
        std::cout << x.first << " " << x.second << std::endl;
    }
    // expected output {{"where",1},{"is",2},{"alice",2},{"wonderland",1},{"great",1}}; order doesn't matter

    std::cout << "EXAMPLE SIX END" << std::endl;
    // ====== end of example: map operations with vector ======

    return 0;
}