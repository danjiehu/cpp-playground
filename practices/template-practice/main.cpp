#include <iostream>
#include <string>

// ex-1: template as function argument
template <typename T>
T max(T x, T y)
{
    return (x > y) ? x : y;
}

// ex-2: template as class member variable
template <typename T>
class List {
private:
    class ListNode {
    public:
        T data; // template typename T as class member variable
        ListNode* next;

        ListNode(const T& value)
            : data(value)
            , next(nullptr) {};
        ~ListNode();
    };

    ListNode* head_;

public:
    // List();
    // ~List();

    void insertAtFront(const T& value);
};

template <typename T>
void List<T>::insertAtFront(const T& value)
{
    ListNode* newNode = new ListNode(value);

    if (!head_) {
        head_ = newNode;
    } else {
        newNode->next = head_;
        head_ = newNode;
    }
}

class person {
public:
    std::string name;
    template <typename T>
    T max(T x, T y)
    {
        return (x > y) ? x : y;
    }
};

int main()
{
    // ex-1: template in function, no association with class
    std::cout << max(10, 20) << std::endl; // template type is defined when the function is called automatically
    std::cout << max<double>(10.4, 20.12) << std::endl; // template type is defined when the function is called with an signed type

    // ex-2: template in variable of class
    // ListNode head(10); causes error, compiler didn't pick up the type automatically
    // ListNode<int> head(10); // template type is defined when the object is created

    // ex-3: template in function of class
    List<int> list;
    list.insertAtFront(10);

    person P;
    std::cout << P.max<double>(50.20, 60) << std::endl; // the function in class template type is defined when the function is called

    return 0;
}