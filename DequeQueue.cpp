// DequeQueue.cpp
#include "DequeQueue.h"
#include <iostream>

DequeQueue::DequeQueue() : front(nullptr), rear(nullptr) {}

DequeQueue::~DequeQueue() {
    while (front) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

void DequeQueue::enqueue(int value) {
    Node* newNode = new Node(value);
    if (!front) {
        front = rear = newNode;
    } else {
        newNode->next = front;
        front = newNode;
    }
}

void DequeQueue::dequeue() {
    if (!front) {
        std::cout << "Deque Queue is empty. Cannot dequeue.\n";
        return;
    }

    Node* temp = front;
    front = front->next;

    if (!front) {
        rear = nullptr; // Queue is now empty
    }

    delete temp;
}

void DequeQueue::displayContents() const {
    std::cout << "Deque Queue contents: ";
    Node* current = front;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}

