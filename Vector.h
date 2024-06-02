#ifndef Vector_h
#define Vector_h

// 2D, for each
template <class M>
class Vector {
private:
    M *arr;
    int last;
    int capacity;

public:
    Vector() {
        arr = new M[1];
        last = -1;
        capacity = 1;
    }

    Vector(int n) {
        arr = new M[n];
        last = n - 1;
        capacity = n;
        for (int i = 0; i < n; ++i) {
            arr[i] = 0;
        }
    }

    Vector(int n, M val) {
        arr = new M[n];
        last = n - 1;
        capacity = n;
        for (int i = 0; i < n; ++i) {
            arr[i] = val;
        }
    }

    int size() {
        return last + 1;
    }

    bool empty() {
        return last == -1;
    }

    void clear() {
        delete[] arr;
        arr = new M[1];
        last = -1;
        capacity = 1;
    }

    void assign(int n, M val) {
        delete[] arr;
        arr = new M[n];
        last = n - 1;
        capacity = n;
        for (int i = 0; i < n; ++i) {
            arr[i] = val;
        }
    }

    M &front() {
        return arr[0];
    }

    M &back() {
        return arr[last];
    }

    void push_back(M val) {
        if (last + 1 == capacity) {
            capacity <<= 1;
            M *newArr = new M[capacity];
            for (int i = 0; i <= last; ++i) {
                newArr[i] = arr[i];
            }
            newArr[++last] = val;
            delete[] arr;
            arr = newArr;
        }
        else {
            arr[++last] = val;
        }
    }

    void pop_back() {
        last--;
    }

    M &operator[](int index) {
        return arr[index];
    }
};

#endif