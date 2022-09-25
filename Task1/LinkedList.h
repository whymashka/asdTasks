#ifndef IVANOVAMARIYA_LINKEDLIST_H
#define IVANOVAMARIYA_LINKEDLIST_H

#include <vector>
#include <optional>
#include <stdexcept>
#include "Node.h"

using namespace std;

// двунаправленный связный список
class LinkedList {

private:

    // поля структуры
    int size_{0};           // кол-вод узлов в списке
    Node* front_{nullptr};  // указатель на начальный узел
    Node* back_{nullptr};   // указатель на конечный узел

public:

    LinkedList() = default;

    ~LinkedList() {
        // эквивалентно очистке списка
        LinkedList::Clear();
    }

    // добавить элемент в конец
    void Add(int value) {
        if(size_ == 0) {
            front_ = new Node(value, nullptr, nullptr);
            back_ = front_;
            size_++;
            return;
        }
        Node *p = new Node(value);
        back_ -> next = p;
        p -> prev = back_;
        back_ = p;
        size_++;
    }

    // удалить элемент в позиции index
    void Remove(int index) {
        if(index < 0 || size_ <= index) return;
        if(size_ == 1) {
            Clear();
        }
        if(index == 0) {
            size_--;
            Node *p = front_;
            front_ = front_ -> next;
            delete p;
            return;
        }

        Node *p = front_;
        for(int i = 0; i < index - 1; i++) p = p -> next;

        if(index == size_ - 1) {
            Node *last = p -> next;
            p -> next = nullptr;
            delete last;
            back_ = p;
            size_--;
            return;
        }
        ((p -> next) -> next) -> prev = p;
        p -> next = (p -> next) -> next;
        size_--;
    }

    //очистить связный список
    void Clear() {
        Node *cur = front_;
        for(int i = 0; i < size_; i++) {
            if(i == size_ - 1) {
                delete cur;
                break;
            }
            Node* mem = cur -> next;
            delete cur;
            cur = mem;
        }
        back_ = front_ = nullptr;
        size_ = 0;
    }

    // вернуть значение элемента на позиции index
    int Get(int index) const {
        Node cur = *front_;
        for(int i = 0; i < index; i++) cur = *cur.next;
        return cur.value;
    }

    int getSize() const {
        return size_;
    }

    // вернуть значение первого элемента
    int front() const {
        return front_ -> value;
    }

    // вернуть значение последнего элемента
    int back() const {
        return back_ -> value;
    }

};

#endif
