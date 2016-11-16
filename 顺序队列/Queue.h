#ifndef _QUEUE_H
#define _QUEUE_H

template<class T>
class Queue
{
public:
    void Clear();
    bool EnQueue(const T item);
    bool DeQueue(T & item);
    bool IsEmpty();
    bool IsFull();
    bool GetFront(T & item);
};

#endif
