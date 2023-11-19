// Keeper.cpp
#include "Keeper.h"
#include <fstream>
#include <iostream>

Keeper::Keeper(int capacity) : size(0), capacity(capacity) {
    queues = new Queue*[capacity];
}

void Keeper::addQueue(Queue* queue) {
    if (size < capacity) {
        queues[size++] = queue;
    } else {
        std::cerr << "Keeper is full. Cannot add more queues.\n";
    }
}

void Keeper::deleteQueue(int index) {
    if (index < 0 || index >= size) {
        std::cerr << "Invalid index\n";
        return;
    }

    delete queues[index];

    for (int i = index; i < size - 1; ++i) {
        queues[i] = queues[i + 1];
    }

    --size;
}

void Keeper::saveToFile(const char* fileName) const {
    std::ofstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << fileName << "\n";
        return;
    }

    for (int i = 0; i < size; ++i) {
        Queue* currentQueue = queues[i];
        int value;
        while ((value = currentQueue->dequeue()) != 0) {
            file << value << " ";
        }
        file << 0;
        file << "\n";
    }
    file.close();
}

void Keeper::loadFromFile(const char* fileName) {
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << fileName << "\n";
        return;
    }

    int value;
    queues[size] = new ListQueue();
    while (file >> value) {
        if (size < capacity) {
            queues[size]->enqueue(value);
        if (value == 0) 
        {
            size++;
            queues[size] = new ListQueue();
        }
        } else {
            std::cerr << "Keeper is full. Cannot add more queues.\n";
            break;
        }
    }

    file.close();
}

void Keeper::display() const {
    for (int i = 0; i < size; ++i) {
        std::cout << "Queue " << i  << ": ";
        queues[i]->display();
    }
}

void Keeper::enqueue(int index, int value) {
    if (index < 0 || index >= size) {
        std::cerr << "Invalid index\n";
        return;
    }

    queues[index]->enqueue(value);
}

void Keeper::dequeue(int index) {
    if (index < 0 || index >= size) {
        std::cerr << "Invalid index\n";
        return;
    }

    int value = queues[index]->dequeue();
    if (value != -1) {
        std::cout << "Dequeued value: " << value << "\n";
    }
}

Keeper::~Keeper() {
    for (int i = 0; i < size; ++i) {
        delete queues[i];
    }
    delete[] queues;
}

