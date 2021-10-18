#include <iostream>
using namespace std;

class box
{
private:
    int length;
    int breadth;
    int *height;

public:
    void set_dimensions(int len, int brea, int heig)
    {
        length = len;
        breadth = brea;
        *height = heig;
    }

    void show_data(obj)
    {
        cout << "length is" << length << ", its address is " << &length
             << "\n breadth is" << breadth << ", its address is " << &breadth
             << "\n height is" << height << ", its address is " << &height << endl;
    }
}