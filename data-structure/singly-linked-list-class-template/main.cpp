#include "List.h"

int main()
{
    List<double> list;

    list.insertAtFront(12);
    list.insertAtFront(5);
    list.insertAtFront(1);

    list.displayList();

    return 0;
}