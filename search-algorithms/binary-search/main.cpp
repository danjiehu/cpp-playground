#include <iostream>

// iterative solution - done
// int binarySearch(int arr[], int value, int low, int high) // unsized array
// {
//     while (low <= high) {
//         int mid = (low + high) / 2;

//         if (value == arr[mid]) {
//             return mid;
//         } else if (value > arr[mid]) {
//             low = mid + 1;
//         } else {
//             high = mid - 1;
//         }
//     }

//     return -1;
// }

// recursive solution, think of the array as having left half and right half
int binarySearch(int arr[], int value, int low, int high) // unsized array
{
    if (low <= high) {
        int mid = (low + high) / 2;
        if (value == arr[mid]) {
            return mid;
        } else if (value > arr[mid]) {
            return binarySearch(arr, value, mid + 1, high); // ! in recursion when calling oneself, remember to return!!!
        } else {
            return binarySearch(arr, value, low, mid - 1);
        }
    }

    return -1;
}

int main()
{
    int arr[6] = { 2, 3, 4, 5, 6, 7 };

    std::cout << binarySearch(arr, 10, 0, 5) << std::endl; // return -1;
    std::cout << binarySearch(arr, 2, 0, 5) << std::endl; // return 0;
    std::cout << binarySearch(arr, 6, 0, 5) << std::endl; // return 4;

    return 0;
}