#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstdint>
#include <iostream>
#include <string>


template<typename T>
struct Node {
    T data;
    Node *next;

    explicit Node(const T &data)
        : data(data),
          next(nullptr) {
    }
};

template<typename T>
std::string toString(Node<T> *node) {
    return "Node: " +
           std::to_string(node->data) +
           "\n";
}

template<typename T>
class LinkedList {
public:
    Node<T> *head = nullptr;

    LinkedList() = default;

    ~LinkedList() {
        Node<T> *curr = head;
        while (curr != nullptr) {
            const Node<T> *temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    void add(T data);

    void print();

    int freq(T &data);

    void deleteSublist(int upperBound);

    [[nodiscard]] uint64_t getSize() const;

private:
    uint64_t size = 0;
};

template<typename T>
void LinkedList<T>::add(T data) {
    auto *newNode = new Node<T>(data);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node<T> *curr = head;
    while (curr->next != nullptr) curr = curr->next;
    curr->next = newNode;
    size++;
}

template<typename T>
void LinkedList<T>::print() {
    Node<T> *curr = head;
    while (curr != nullptr) {
        std::cout << toString(curr);
        curr = curr->next;
    }
}

template<typename T>
int LinkedList<T>::freq(T &data) {
    Node<T> *curr = head;
    int freq = 0;
    while (curr != nullptr) {
        if (curr->data == data) freq++;
        curr = curr->next;
    }
    return freq;
}

template<typename T>
void LinkedList<T>::deleteSublist(const int upperBound) {
    Node<T> *curr = head;
    int i = 0;
    while (curr != nullptr && i < upperBound) {
        const Node<T> *temp = curr;
        curr = curr->next;
        delete temp;
        i++;
    }
    head = curr;
    size -= upperBound;
}

template<typename T>
uint64_t LinkedList<T>::getSize() const {
    return size;
}


#endif //LINKEDLIST_H
