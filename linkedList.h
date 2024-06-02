#ifndef linkedList_h
#define linkedList_h

#include <iostream>
using namespace std;

class linkedList {
private:
    struct node {
        int data;
        node *next = nullptr;
    };
    node *list;

public:
    linkedList() {
        list = nullptr;
    }

    ~linkedList() {
        while (list) {
            removeFirst();
        }
    }

    void addFirst(int x) {
        node *p = new node;
        p->data = x;
        p->next = nullptr;

        if (list) {
            p->next = list;
            list = p;
        }
        else {
            list = p;
        }
    }

    void addLast(int x) {
        node *p = new node;
        p->data = x;
        p->next = nullptr;

        if (list) {
            node *q = list;
            while (q->next) {
                q = q->next;
            }
            q->next = p;
        }
        else {
            list = p;
        }
    }

    void addAfter(int x, int pos) {
        if (pos == 1) {
            addFirst(x);
            return;
        }

        node *p = new node;
        p->data = x;
        p->next = nullptr;

        node *q = list;
        for (int i = 1; i <= pos - 1; i++) {
            if (q == nullptr) {
                cout << "Position not found.\n";
                return;
            }
            if (i == pos - 1) {
                p->next = q->next;
                q->next = p;
                return;
            }
            q = q->next;
        }
    }

    int removeFirst() {
        if (list == nullptr) {
            cout << "List is empty.\n";
            return -1;
        }
        int ret = list->data;
        node *p = list;
        list = list->next;
        delete (p);
        return ret;
    }

    int removeLast() {
        if (list == nullptr) {
            cout << "List is empty.\n";
            return -1;
        }
        if (list->next) {
            node *q = list;
            while (q->next->next) {
                q = q->next;
            }
            int ret = q->next->data;
            delete (q->next);
            q->next = nullptr;
            return ret;
        }
        else {
            return removeFirst();
        }
    }

    void removeData(int data) {
        if (list == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (list->data == data) {
            removeFirst();
            return;
        }
        if (list->next == nullptr) {
            cout << "Data not found.\n";
            return;
        }

        node *q = list;
        while (q->next->data != data) {
            if (q->next->next == nullptr) {
                cout << "Data not found.\n";
                return;
            }
            q = q->next;
        }

        node *temp = q->next;
        q->next = q->next->next;
        delete (temp);
    }

    int search(int data) {
        if (list == nullptr) {
            cout << "List is empty.\n";
            return -1;
        }
        int pos = 1;
        node *q = list;
        while (q) {
            if (q->data == data) {
                return pos;
            }
            pos++;
            q = q->next;
        }
        return -1;
    }

    void display() {
        node *q = list;
        while (q) {
            cout << q->data << " ";
            q = q->next;
        }
        cout << '\n';
    }
};

#endif