// Queue.h
#ifndef QUEUE_H
#define QUEUE_H

class Queue {
public:
    virtual void enqueue(int value) = 0;
    virtual int dequeue() = 0;
    virtual void display() const = 0;
    virtual ~Queue() {}
};

#endif // QUEUE_H

