#ifndef Priority_queue_h
#define Priority_queue_h
#include "Vector.h"

template <class T>
class Priority_queue {
private:
    Vector<T> v;

    void heapify(int idx) {
        int l = 2 * idx + 1;
        int r = 2 * idx + 2;
        int mx = idx;
        if (l < v.size() && v[mx] < v[l]) {
            mx = l;
        }
        if (r < v.size() && v[mx] < v[r]) {
            mx = r;
        }
        if (mx != idx) {
            swap(v[mx], v[idx]);
            heapify(mx);
        }
    }

public:
    int size() {
        return v.size();
    }

    bool empty() {
        return v.empty();
    }

    void pop() {
    }

    void push(T x) {
        v.push_back(x);
        int cur = v.size() - 1;
        while (cur) {
            heapify(cur);
            cur = (cur - 1) / 2;
        }
        heapify(0);
    }

    T top() {
        return v[0];
    }
};

#endif