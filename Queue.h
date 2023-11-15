// Queue.h
#ifndef QUEUE_H
#define QUEUE_H

// Abstract class Queue
class Queue {
public:
    virtual void enqueue(int value) = 0;
    virtual void dequeue() = 0;
    virtual void displayContents() const = 0;
    virtual ~Queue() = default;
};

#endif // QUEUE_H

