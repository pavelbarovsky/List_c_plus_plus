#include <iostream>
#include <inttypes.h>
using namespace std;

template <typename T>
class DoubleList {
    class Node {
    public:
        Node* next;
        Node* prev;
        T data;
        Node() {
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head;
    Node* tale;
    size_t size;
public:
    DoubleList() {
        head = nullptr;
        tale = nullptr;
    }
    ~DoubleList() {
        clear();
    }

    void clear() {
        Node* temp = head;
        Node* forDeletion = head;
        while (temp != nullptr) {
            temp = temp->next;
            delete forDeletion;
            forDeletion = temp;
        }
        head = nullptr;
        size = 0;
    }

    T popBack() {
        T temp = tale->data;
        tale = tale->prev;
        delete tale->next;
        size--;
        return temp;
    }

    T popFront() {
        T temp = head->data;
        head = head->next;
        delete head->prev;
        size--;
        return temp;
    }

    void pushBack(T newElement) {
        if (head == nullptr) {
            head = new Node();
            tale = head;
        }
        else {
            tale->next = new Node();
            tale->next->prev = tale;
            tale = tale->next;
        }

        tale->data = newElement;
        size++;
    }

    void pushFront(T newElement) {
        if (head == nullptr) {
            head = new Node();
            tale = head;
        }
        else {
            head->prev = new Node();
            head->prev->next = head;
            head = head->prev;
        }
        head->data = newElement;
        size++;
    }

    size_t Size() {
        return size;
    }

    T& at(int index) {
        if (index > size) {
            cout << endl << "vector subscript is out of range!";
            exit(0);
        }
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    };

    T& operator [](int index) {
        return at(index);
    };
};
