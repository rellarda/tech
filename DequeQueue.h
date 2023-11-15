// DequeQueue.h
#ifndef DEQUE_QUEUE_H
#define DEQUE_QUEUE_H
#include "Queue.h"

// Concrete class implementing Queue using double-ended linked list
class DequeQueue : public Queue {
private:
    struct Node {
        int data;
        Node* next;

        Node(int value) : data(value), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    DequeQueue();
    ~DequeQueue();

    void enqueue(int value) override;
    void dequeue() override;
    void displayContents() const override;
};

#endif // DEQUE_QUEUE_H

