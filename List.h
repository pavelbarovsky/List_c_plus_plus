#include <iostream>
#include <inttypes.h>
using namespace std;

template <typename T>
class List {
    class Node {
    public:
        Node* next;
        T data;
        Node() {
            next = nullptr;
        }
    };

    Node* head;
    Node* tale;
    size_t size;

public:
    List() {
        head = nullptr;
    };
    ~List() {
        clear();
    };
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
    };

    void add(T newElement) {
        if (head == nullptr) {
            head = new Node();
            tale = head;
        }
        else {
            tale->next = new Node();
            tale = tale->next;
        }
        tale->data = newElement;
        size++;
    }


    size_t Size() { return size; }


    T& at(int index) {
        if (index > size) {
            cout << endl << "Векторный индекс не в диапазоне!";
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
