// ListQueue.cpp
#include "ListQueue.h"
#include <iostream>

ListQueue::ListQueue() : front(nullptr), rear(nullptr) {}

ListQueue::~ListQueue() {
    while (front) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

void ListQueue::enqueue(int value) {
    Node* newNode = new Node(value);
    if (!front) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void ListQueue::dequeue() {
    if (!front) {
        std::cout << "List Queue is empty. Cannot dequeue.\n";
        return;
    }

    Node* temp = front;
    front = front->next;

    if (!front) {
        rear = nullptr; // Queue is now empty
    }

    delete temp;
}

void ListQueue::displayContents() const {
    std::cout << "List Queue contents: ";
    Node* current = front;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}

