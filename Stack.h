#ifndef Stack_h
#define Stack_h

template <class T>
class Stack {
private:
    struct node {
        T val;
        node *address = nullptr;
    };
    node *Top;
    int Size;

public:
    Stack() : Top(nullptr), Size(0) {}

    void push(int x) {
        Size++;
        node *newNode = new node;
        newNode->val = x;
        newNode->address = Top;
        Top = newNode;
    }

    void pop() {
        Size--;
        node *temp = Top;
        Top = Top->address;
        delete temp;
    }

    T top() {
        return Top->val;
    }

    int size() {
        return Size;
    }

    bool empty() {
        return !Size;
    }
};

#endif