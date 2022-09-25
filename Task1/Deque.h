#ifndef IVANOVAMARIYA_DEQUE_H
#define IVANOVAMARIYA_DEQUE_H

#include "LinkedList.h"
#include <cstddef>

class Deque {
private:
    size_t size{0};
    LinkedList list;

public:
    Deque() = default;

    void enqueue(int value) {
        list.Add(value);
        size++;
    }

    int dequeue() {
        int res = list.front();
        list.Remove(0);
        return res;
    }

    int get(int index) {
        return list.Get(index);
    }
};

#endif //IVANOVAMARIYA_DEQUE_H
