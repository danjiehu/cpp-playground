#include "List.h"

int main()
{
    List<double> list;

    // testing insert, display
    list.insertAtFront(12);
    list.insertAtFront(5);
    list.insertAtFront(1);
    list.displayList();
    cout << "size of list is: " << list.size() << endl;

    // testing [] overload
    cout << list[0] << endl;
    cout << list[1] << endl;
    cout << list[2] << endl;
    // cout << list[3] << endl; // segmentation fault

    // testing appendNode
    list.appendNode(13);
    list.displayList();

    // testing delete at front
    list.deleteAtFront();
    list.displayList();

    // testing delete at end
    list.deleteAtEnd();
    list.displayList();

    return 0;
}