// DequeQueue.h
#ifndef DEQUEQUEUE_H
#define DEQUEQUEUE_H

#include "Queue.h"

class DequeQueue : public Queue {
private:
    int* data;
    int capacity;
    int front;
    int rear;

public:
    DequeQueue(int capacity);
    void enqueue(int value) override;
    int dequeue() override;
    void display() const override;
    ~DequeQueue();
};

#endif // DEQUEQUEUE_H

