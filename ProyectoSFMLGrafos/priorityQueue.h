#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

template <typename E>
class priorityQueue{
private:
    void operator=(const priorityQueue &obj){}
    priorityQueue(const priorityQueue &obj){}

public:
    priorityQueue(){}
    virtual ~priorityQueue(){}
    virtual void insert(E element, int priority)=0;
    virtual E min()=0;
    virtual E removeMin()=0;
    virtual int getSize()=0;
    virtual bool isEmpty()=0;
};

#endif // PRIORITYQUEUE_H
