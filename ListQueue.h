// ListQueue.h
#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H
#include "Queue.h"

// Concrete class implementing Queue using linked list
class ListQueue : public Queue {
private:
    struct Node {
        int data;
        Node* next;

        Node(int value) : data(value), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    ListQueue();
    ~ListQueue();

    void enqueue(int value) override;
    void dequeue() override;
    void displayContents() const override;
};

#endif // LIST_QUEUE_H

