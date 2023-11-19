// StackQueue.h
#ifndef STACKQUEUE_H
#define STACKQUEUE_H

#include "Queue.h"

class StackQueue : public Queue {
private:
    int* data;
    int capacity;
    int front;
    int rear;

public:
    StackQueue(int capacity);
    void enqueue(int value) override;
    int dequeue() override;
    void display() const override;
    ~StackQueue();
};

#endif // STACKQUEUE_H

