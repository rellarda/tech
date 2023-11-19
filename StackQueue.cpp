// StackQueue.cpp
#include "StackQueue.h"
#include <iostream>

StackQueue::StackQueue(int capacity) : capacity(capacity), front(0), rear(0) {
    data = new int[capacity];
}

void StackQueue::enqueue(int value) {
    if (rear == capacity) {
        std::cerr << "Queue is full\n";
        return;
    }

    data[rear++] = value;
}

int StackQueue::dequeue() {
    if (front == rear) {
        std::cerr << "Queue is empty\n";
        return -1; // Error value for an empty queue
    }

    int value = data[front++];
    return value;
}

void StackQueue::display() const {
    for (int i = front; i < rear; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

StackQueue::~StackQueue() {
    delete[] data;
}

