#ifndef Queue_h
#define Queue_h

template <class T>
class Queue {
private:
    struct node {
        T val;
        node *after = nullptr;
        node *before = nullptr;
    };
    node *Front, *Back;
    int Size;

public:
    Queue() : Front(nullptr), Back(nullptr), Size(0) {}

    int size() {
        return Size;
    }

    bool empty() {
        return !Size;
    }

    T front() {
        return Front->val;
    }

    T back() {
        return Back->val;
    }

    void push(T x) {
        Size++;
        if (Size == 1) {
            Front = new node;
            Front->val = x;
            Front->after = Front->before = nullptr;
            Back = Front;
            return;
        }
        node *newNode = new node;
        Back->after = newNode;
        newNode->val = x;
        newNode->after = nullptr;
        newNode->before = Back;
        Back = newNode;
    }

    void pop() {
        Size--;
        if (Size == 0) {
            delete Front;
            Front = Back = nullptr;
            return;
        }
        node *temp = Front;
        Front = Front->after;
        Front->before = nullptr;
        delete temp;
    }
};

#endif