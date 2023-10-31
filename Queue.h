class Queue
{
    Queue();
    Queue(int a);
    virtual ~Queue(); 
    Queue(const Queue &queue);

    void Push(int a);
    int Pop();
};
