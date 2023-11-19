// main.cpp
#include <iostream>
#include "ListQueue.h"
#include "StackQueue.h"
#include "DequeQueue.h"
#include "Keeper.h"

int main() {
    Keeper keeper(5);

    while (true) {
        int option;
        std::cout << "Choose an option:\n"
                  << "1. Add Queue\n"
                  << "2. Delete Queue\n"
                  << "3. Enqueue\n"
                  << "4. Dequeue\n"
                  << "5. Display\n"
                  << "6. Save to File\n"
                  << "7. Load from File\n"
                  << "0. Exit\n";
        std::cin >> option;

        switch (option) {
            case 1: {
                int type;
                std::cout << "Choose type of queue (1: List, 2: Stack, 3: Deque): ";
                std::cin >> type;

                Queue* queue;
                if (type == 1) {
                    queue = new ListQueue();
                } else if (type == 2) {
                    int capacity;
                    std::cout << "Enter capacity for the stack-based queue: ";
                    std::cin >> capacity;
                    queue = new StackQueue(capacity);
                } else if (type == 3) {
                    int capacity;
                    std::cout << "Enter capacity for the deque-based queue: ";
                    std::cin >> capacity;
                    queue = new DequeQueue(capacity);
                } else {
                    std::cout << "Invalid option\n";
                    continue;
                }

                keeper.addQueue(queue);
                break;
            }
            case 2: {
                int index;
                std::cout << "Enter index of queue to delete: ";
                std::cin >> index;
                keeper.deleteQueue(index);
                break;
            }
            case 3: {
                int index, value;
                std::cout << "Enter index of queue to enqueue: ";
                std::cin >> index;
                std::cout << "Enter value to enqueue: ";
                std::cin >> value;
                keeper.enqueue(index, value);
                break;
            }
            case 4: {
                int index = 0;
                std::cout << "Enter index of queue to dequeue: ";
                std::cin >> index;
                keeper.dequeue(index);
                break;
            }
            case 5:
                keeper.display();
                break;
            case 6: {
                const char* fileName = "queues.txt";
                keeper.saveToFile(fileName);
                std::cout << "Queues saved to " << fileName << std::endl;
                break;
            }
            case 7: {
                const char* fileName = "queues.txt";
                keeper.loadFromFile(fileName);
                std::cout << "Queues loaded from " << fileName << std::endl;
                break;
            }
            case 0:
                return 0;
            default:
                std::cout << "Invalid option\n";
        }
    }

    return 0;
}

