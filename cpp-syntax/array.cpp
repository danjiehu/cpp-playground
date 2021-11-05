// ! consider using std::<vector> which is easier to maintain and you can print much easier
// array ref: https://www.youtube.com/watch?v=ENDaJi08jCU&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=31
#include <array>
#include <iostream>

using std::cout;
using std::endl;

// TODO: learn how to overload << to cout array

int main()
{
    // #include <array>: stack
    std::array<int, 5> m_array1;
    // alternatively:
    // std::array<int, 5> m_array1 = { 0, 1, 2, 3, 4 };
    for (int i = 1; i < m_array1.size(); i++) {
        m_array1[i] = i;
    }

    for (int i = 0; i < m_array1.size(); i++) {
        cout << "m_array1: " << &m_array1[i] << " " << m_array1[i] << endl;
    }

    // raw stack array
    static const int m_array2_size = 5;
    // ! size has to be a compile-time known constant, therefore "static const int"
    // ! defining size const because there's no way to know raw array size precisely and easily
    int m_array2[m_array2_size] = { 0, 1, 2, 3, 4 };
    cout << "address of first array element: " << m_array2 << endl; // print address of first allocated int i.e. 2
    for (int i = 0; i < m_array2_size; i++) {
        cout << "m_array2: " << &m_array2[i] << " " << m_array2[i] << endl;
    }

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