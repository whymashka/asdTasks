#ifndef IVANOVAMARIYA_STACK_H
#define IVANOVAMARIYA_STACK_H

#include <cstddef>
#include "LinkedList.h"

class Stack {
private:
    size_t size{0};
    LinkedList list;

public:

    Stack() = default;

    // добавить элемент
    void push(int value) {
        list.Add(value);
        size++;
    }

    // взять последний добавленный элемент не удаляя его
    int peek() {
        if(size == 0) {
            //выбрасываем исключение
            throw runtime_error("Stack is empty");
        }
        return list.back();
    }

    // взять последний добавленный элемент удалив его
    int pop() {
        if(size == 0) {
            //выбрасываем исключение
            throw runtime_error("Stack is empty");
        }
        int res = list.back();
        list.Remove(size - 1);
        size--;
        return res;
    }
};

#endif
