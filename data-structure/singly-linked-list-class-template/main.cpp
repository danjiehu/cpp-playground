#include "List.h"

int main()
{
    List<double> list;

    list.insertAtFront(12);
    list.insertAtFront(5);
    list.insertAtFront(1);

    list.displayList();

    cout << list[0] << endl;
    cout << list[1] << endl;
    cout << list[2] << endl;
    cout << list[3] << endl; // segmentation fault

    return 0;
}