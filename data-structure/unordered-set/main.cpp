// this file is to demostrate the use of std::unordered_set
// class ref 4-3 graph search project: https://d3c33hcgiwev3.cloudfront.net/gSsGRHheEem3uwrt2iBKLA_735536444faa4a22a92d1ddf34221ee4_graph_search_project_instructions_20190516b.pdf?Expires=1642464000&Signature=hCMmhNLMJkwZ6vUppkW3nYPAFzEq7KtjB-LGiRTP1aggAGC5A55JHc~Ty9NrxLB8sNOaEBwl-La-ijvsGD6Xo0gEE1Fe6QwW182A8EdPfRCD8OAEMvz9Z2MGWC6TyjncNE6zninGxPNrO2VF547z1rlFcEOT8udx-9QjlTQXwGI_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A

// what std::unordered_set is:
// 1. contains value copies of objects and no duplicates, inserting the same item twice has no effect.
// 2. uses hash internally.
// 3. unlike std::unordered_map, the keys for an unordered set do not have associated values.we only care about if a given key has been inserted or not.

// use of the std::unordered_set:
// 1. labelling vertices with some status; for example if an algorithm tells you to label vertices as "visited", we could instead make a set for all the visited vertices and insert copies of vertices to the visited set when we want to record that these vertices have been visited.

// std::unordered_set time complexity:
// O(1) in general on all operations, worst case can go up to O(n) depending on the internal hashing function used.

#include <iostream>
#include <string>
#include <unordered_set>

int main()
{
    std::unordered_set<int> favNumbers;
    std::unordered_set<std::string> emptyStringSet;

    favNumbers.insert(7);
    favNumbers.insert(42);
    // inserting again doesn't change anything;
    favNumbers.insert(42);

    // size()
    std::cout << "size: " << favNumbers.size() << std::endl;
    // empty()
    std::cout << "if favNumbers is empty: " << favNumbers.empty() << std::endl;
    std::cout << "if emptyStringSet is empty: " << emptyStringSet.empty() << std::endl;
    // count(7) to query if an item exist in set;
    // erase(7) to remove item from a set;
    std::cout << "if 7 exist in set: " << favNumbers.count(7) << std::endl;
    favNumbers.erase(7);
    std::cout << "if 7 exist in set after erase(7): " << favNumbers.count(7) << std::endl;

    return 0;
}