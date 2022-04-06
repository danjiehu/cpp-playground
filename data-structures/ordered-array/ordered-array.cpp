// common operarion big(o) summary for an ordered array
// read: o(1)
// search - linear search: o(n); binary search: o(log N)
// insert - insert in front; insert at the back; insert in the middle
// delete

#include <iostream>

int main()
{
    static const int n = 6;
    int arr[n] = { 0, 1, 2, 3, 4, 5 };

    // read: always o(1)
    // reading an element of an array has nothing to do with array size n
    std::cout << arr[2] << std::endl;

    // search algo 1:
    // linear search worst case scenario: o(n)
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

    // search algo 2:
    // binary search worst case scenario(log N)
    // o(log N) means that the algorithm takes as many steps as it takes to keep halving the data elements until we remain with one
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

    // insertion algo
    // 1. resize the array:
    //  1.1 grow array by 2 each time, adding n elements takes a total of o(n^2) ！arithmetic sequence 等差数列求和
    //  1.2 double array each time, adding n elements takes a total of o(n), amortized running time is o(n)/n == o(1) ！geometric sequence 等比数列求和
    //  *amortized time is the way to express the time complexity when an algorithm has the very bad time complexity only once in a while besides the time complexity that happens most of time.
    // 2. copy over the old data and insert, depending on where in an array the insertion happens

    // insert in front

    // insert in middle

    // insert at the back

    // delete
    std::cin.get();
}
