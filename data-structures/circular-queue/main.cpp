#include <iostream>
using std::cout;
using std::endl;
// using heap array to demostrate circular queue
// why we use circular queue: https://www.youtube.com/watch?v=V6X6yXvT9uI
// an simpler way of finding the rear index is rear = (rear+1)%size
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
void Queue::deQueue()
{
    // if queue is empty
    // if queue is only one element: need to update both rear and front
    // if queue has 1+ elements: just need to update front
    if (front == -1) {
        cout << "cannot dequeue because the queue is already empty" << endl;
    } else if (front == rear) {
        int d_value = arr[front];
        front = -1;
        rear = -1;
        element_cout--;
        cout << "dequeued " << d_value << endl;
    } else {
        int d_value = arr[front];
        if (front + 1 == size) {
            front = 0;
        } else {
            front = front + 1;
        }
        element_cout--;
        cout << "dequeued " << d_value << endl;
    }
}

// start of displayQueue
void Queue::displayQueue()
{
    cout << "displaying queue: ";
    // queue is empty
    // queue has only one element
    // queue has 2+ element, rear >= front
    // queue has 2+ element, rear < front

    if (front == -1) {
        cout << "queue is empty" << endl;
    } else if (rear >= front) {
        for (int i = front; i < rear + 1; i++) {
            cout << arr[i] << " ";
        }
    } else {
        for (int i = front; i < size; i++) {
            cout << arr[i] << " ";
        }
        for (int i = 0; i < rear + 1; i++) {
            cout << arr[i] << " ";
        }
    }

    cout << endl;
};

int main()
{
    Queue q(3);
    q.enQueue(20);
    q.enQueue(21);
    q.enQueue(22);
    q.enQueue(23); // already full
    q.displayQueue();

    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue(); // queue is empty
    q.displayQueue();

    q.enQueue(30);
    q.enQueue(31);
    q.enQueue(32);
    q.displayQueue(); // expected: 30 31 32
    q.deQueue();
    q.deQueue();
    q.displayQueue(); // expected: 32
    q.enQueue(33);
    q.enQueue(34);
    q.displayQueue(); // expected: 32 33 34

    return 0;
}