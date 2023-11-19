// Keeper.h
#ifndef KEEPER_H
#define KEEPER_H

#include "Queue.h"
#include "ListQueue.h"

class Keeper {
private:
    Queue** queues;
    int size;
    int capacity;

public:
    Keeper(int capacity);
    void addQueue(Queue* queue);
    void deleteQueue(int index);
    void saveToFile(const char* fileName) const;
    void loadFromFile(const char* fileName);
    void display() const;
    void enqueue(int index, int value);
    void dequeue(int index);
    ~Keeper();
};

#endif // KEEPER_H

