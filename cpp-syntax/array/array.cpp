// ! consider using std::<vector> which is easier to maintain and you can print much easier
// array ref: https://www.youtube.com/watch?v=ENDaJi08jCU&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=31

/** NOTES **/
// array elements are all the same data type
// element size (number of bytes) of the data type is fixed

// TODO: learn how to overload << to cout array

#include <array>
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    cout << " --- new --- example --- " << endl;
    // sizeof(), offset, convert hexadecimal to decimal
    int int_arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    cout << "size of int: " << sizeof(int) << " bytes" << endl;
    cout << "&(int_arr[5]): " << &(int_arr[5]) << endl;
    //(long) cast memory address number from HEX to DEC measurement
    cout << "memory in decimal: " << (long)&(int_arr[5]) << endl;
    // offset is describing memory distance in decimal measurement
    // ! we do this conversion because when we describe size of data type, i.e. int is 4 bytes, the measurement is in DEC
    int offset = (long)&(int_arr[5]) - (long)&(int_arr[0]);
    // ! offset [5]to[0] = sizeof(int)*(5-0) = 4*5 = 20
    cout << "int_arr[0] to int_arr[5] offset is: " << offset << endl;

    cout << " --- new --- example --- " << endl;
    // using array template: #include <array>
    std::array<int, 5> m_array1;
    // alternatively:
    // std::array<int, 5> m_array1 = { 0, 1, 2, 3, 4 };
    for (int i = 1; i < m_array1.size(); i++) {
        m_array1[i] = i;
    }

    for (int i = 0; i < m_array1.size(); i++) {
        cout << "m_array1: " << &m_array1[i] << " " << m_array1[i] << endl;
    }

    cout << " --- new --- example --- " << endl;
    // raw stack array
    static const int m_array2_size = 5;
    // ! size has to be a compile-time known constant, therefore "static const int"
    // ! defining size const because there's no way to know raw array size precisely and easily
    int m_array2[m_array2_size] = { 0, 1, 2, 3, 4 };
    cout << "address of first array element: " << m_array2 << endl; // print address of first allocated int i.e. 2
    for (int i = 0; i < m_array2_size; i++) {
        cout << "m_array2: " << &m_array2[i] << " " << m_array2[i] << endl;
    }

    cout << " --- new --- example --- " << endl;
    // raw heap array
    static const int m_array3_size = 5;
    int* m_array3_ptr = new int[m_array3_size];
    for (int i = 0; i < m_array3_size; i++) {
        m_array3_ptr[i] = i;
        // ! notice how we didn't have to dereference here
        cout << "m_array3: " << m_array3_ptr << " " << m_array3_ptr[i] << endl;
    };

    delete[] m_array3_ptr;
    m_array3_ptr = nullptr;

    return 0;
}

//! below: don't work
// std::ostream& operator<<(std::ostream& stream, const std::array& other)
// {
//     for (int i = 0; i < other.size(); i++) {
//         stream << other[i] << " ";
//     }
//     return stream;
// }
// std::array* m_array3_ptr = new std::array;
// *m_array3_ptr = { 0, 1, 2, 3, 4 };