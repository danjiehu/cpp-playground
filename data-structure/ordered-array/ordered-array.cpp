// this cpp file is used to analyze the common operations done on ordered array and its big o
// common data operation: read, search, insert delete
#include <iostream>

int main()
{
    static const int n = 6;
    int arr[n] = { 0, 1, 2, 3, 4, 5 };

    // read:
    // o(1)
    // reading an element of an array has nothing to do with array size n
    std::cout << arr[2] << std::endl;

    // search algo 1: linear search
    // o(n)
    // worst case scenario it takes n steps
    int target = 5;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            std::cout << "linear search found target element at index: " << i << std::endl;
            break;
        }
        if (i == 5) {
            std::cout << "linear search: target element doesn't exist" << std::endl;
        }
    };

    // search algo 2:  binary search
    // o(log N): o(log N) means that the algorithm takes as many steps as it takes to keep halving the data elements until we remain with one

    int upper_index = n - 1;
    int lower_index = 0;
    int mid_index = (upper_index + lower_index) / 2;

    while (upper_index >= lower_index) {
        if (arr[mid_index] == target) {
            std::cout << "binary search: found element at index: " << mid_index << std::endl;
            break;
        } else if (target > arr[mid_index]) {
            lower_index = mid_index + 1;
            mid_index = (upper_index + lower_index) / 2;
            if (lower_index > mid_index) {
                std::cout << "binary search: target element doesn't exist" << std::endl;
            };
        } else {
            upper_index = mid_index - 1;
            mid_index = (upper_index + lower_index) / 2;
            if (upper_index < mid_index) {
                std::cout << "binary search: target element doesn't exist" << std::endl;
            };
        }
    };

    // insert
    // delete
    std::cin.get();
}
