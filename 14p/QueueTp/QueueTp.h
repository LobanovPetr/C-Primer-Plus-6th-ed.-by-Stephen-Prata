#ifndef QUEUETP_
#define QUEUETP_
#include <cstddef>

namespace mns
{

using std::size_t;

template<typename T>
class Queue
{
private:
    struct Node
    {
        T value;
        Node * next;
        explicit Node(const T& val, Node* ptr = nullptr): value(val), next(ptr) {}
    };
    Node* root;
    Node* last;
    size_t qsize;
public:
    Queue();
    Queue(const Queue&);
    Queue& operator=(const Queue&);
    
    bool isempty() const { return qsize == 0; };
    const T& back() const { return last->value; }
    const T& front() const { return root->value; }
    T& back() { return last->value; }
    T& front() { return root->value; }
    void push(const T&);
    void pop();
    size_t size() const { return qsize; }
    ~Queue();
};

template<typename T>
Queue<T>::Queue() : root(nullptr), last(nullptr), qsize(0) { }

template<typename T>
Queue<T>::Queue(const Queue<T>& q)
{
    if (q.qsize == 0)
    {
        root = nullptr;
        last = nullptr;
        qsize = 0;
        return;
    }
    Node * tmp1 = root = new Node(q.root->value);
    Node * tmp2 = q.root->next;
    qsize = q.qsize;
    
    while(tmp2 != nullptr)
    {
        tmp1->next = new Node(tmp2->value);
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    last = tmp1;
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& q)
{
    if (this == &q)
        return *this;
    Node * tmp1 = root;
    while(root != nullptr)
    {
        root = root->next;
        delete tmp1;
        tmp1 = root;
    }
    if (q.qsize == 0)
    {
        root = nullptr;
        last = nullptr;
        qsize = 0;
        return *this;
    }
    tmp1 = root = new Node(q.root->value);
    Node * tmp2 = q.root->next;
    qsize = q.qsize;
    
    while(tmp2 != nullptr)
    {
        tmp1->next = new Node(tmp2->value);
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    last = tmp1;
    return *this;
}

template<typename T>
void Queue<T>::push(const T& v)
{
    qsize++;
    if (last == nullptr)
    {
        last = new Node(v);
        root = last;
        return;
    }
    last->next = new Node(v);
    last = last->next;
}

template<typename T>
void Queue<T>::pop()
{
    if (qsize == 0)
        return;
    qsize--;
    Node * tmp = root;
    root = root->next;
    delete tmp;
    if (root == nullptr)
        last = nullptr;
}

template<typename T>
Queue<T>::~Queue()
{
    Node * tmp1 = root;
    while(root != nullptr)
    {
        root = root->next;
        delete tmp1;
        tmp1 = root;
    }
    last = nullptr;
    qsize = 0;
}

}

#endif
