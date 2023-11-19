// ListQueue.h
#ifndef LISTQUEUE_H
#define LISTQUEUE_H

#include "Queue.h"

class ListQueue : public Queue {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    ListQueue();
    void enqueue(int value) override;
    int dequeue() override;
    void display() const override;
    ~ListQueue();
};

#endif // LISTQUEUE_H

