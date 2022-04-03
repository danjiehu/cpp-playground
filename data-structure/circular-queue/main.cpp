#include <iostream>
using std::cout;
using std::endl;
// using heap array to demostrate circular queue
// why we use circular queue: https://www.youtube.com/watch?v=V6X6yXvT9uI
// Circular Queues offer a efficient way to store FIFO data with a maximum size

// if the class is declared using the keyword class then its members are private by default;
// if it is declared using the keyword struct or union then its members are public by default.

class Queue {
private: // can omit as it's by default private
    // initialize front and rear
    int rear, front; // this is to keep track of in the array (storing the first element), which index is the front and which index is rear (storing the last element)
    int size; // this is an int queue, so size refers to how many int can this queue have maximumly
    int* arr; // this is the actual array container, will create it in heap so we are using pointers
    int element_cout;

public:
    // function 1. constructor with paramter, input max size (number of int able to store)
    Queue(int s)
    {
        element_cout = 0;
        front = rear = -1; // front = rear = -1 queue is empty
        size = s; // size of the heap array
        arr = new int[s]; // creating a heap arr, starter address stored in arr
    }

    // function 2. enQueue
    void enQueue(int value);
    // function 3. deQueue
    void deQueue();
    // function 4. displayQueue();
    void displayQueue();
    // function 5. destructor to destroy heap arr
    ~Queue()
    {
        delete[] arr;
    };
};

// start of enQueue
void Queue::enQueue(int value)
{
    // enqueuing first element
    if (front == -1) {
        front = rear = 0;
        arr[front] = value;
        element_cout++;
        cout << value << " enqueue completed" << endl;
    } else if (element_cout == size) {
        cout << value << " enqueue failed because the queue is full." << endl; // if queue is full: front and rear index has a difference of 1
    } else if (rear + 1 == size) { // if queue is not full but index rear+1 acceeded array size
        arr[0] = value;
        rear = 0;
        element_cout++;
        cout << value << " enqueue completed" << endl;
    } else {
        arr[rear + 1] = value; //  if queue is not full but index rear+1 hasn't acceed array size
        rear++;
        element_cout++;
        cout << value << " enqueue completed" << endl;
    }

    // displayQueue();
}

// start of deQueue

// start of displayQueue
void Queue::displayQueue()
{
    // queue is empty
    // queue is not empty, rear >= front
    // queue is not empty, rear < front
    if (front == -1) {
        cout << "queue is empty" << endl;
    } else if (rear >= front) {
        for (int i = front; i < rear + 1; i++) {
            cout << arr[i] << " ";
        }
    } else {
        for (int i = front; i < size + 1; i++) {
            cout << arr[i] << " ";
        }
        for (int i = 0; i < rear + 1; i++) {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    Queue q(3);
    q.enQueue(20);
    q.enQueue(21);
    q.enQueue(22);

    q.enQueue(23); // already full
    q.displayQueue();

    return 0;
}