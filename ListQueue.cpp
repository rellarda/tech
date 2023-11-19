// ListQueue.cpp
#include "ListQueue.h"
#include <iostream>

ListQueue::ListQueue() : front(nullptr), rear(nullptr) {}

void ListQueue::enqueue(int value) {
    Node* newNode = new Node(value);
    if (!rear) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int ListQueue::dequeue() {
    if (!front) {
        std::cerr << "Queue is empty\n";
        return -1; // Error value for an empty queue
    }

    int value = front->data;
    Node* temp = front;
    front = front->next;
    if (!front) {
        rear = nullptr; // Queue is now empty
    }
    delete temp;
    return value;
}

void ListQueue::display() const {
    Node* current = front;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}

ListQueue::~ListQueue() {
    while (front) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

