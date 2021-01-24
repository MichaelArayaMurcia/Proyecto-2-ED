#ifndef LINKEDPRIORITYQUEUE_H
#define LINKEDPRIORITYQUEUE_H
#include "priorityQueue.h"
#include "Linkedqueue.h"
#include <stdexcept>

using namespace std;
template<typename E>
class LinkedPriorityQueue : public priorityQueue<E>{
private:
    Linkedqueue<E> *queues;
    int size;
    int priorities;

public:
    LinkedPriorityQueue(int priorities){
        if(priorities<=0){
            throw runtime_error("the number of priorities must be greater than zero.");
        }
        queues = new Linkedqueue<E>[priorities];
        size = 0;
        this->priorities=priorities;
    }
    ~LinkedPriorityQueue(){
        delete [] queues;
    }
    void insert(E element, int priority = 0){
        if(priority < 0 || priority >= priorities){
            throw runtime_error("Invalid priority.");
        }
        queues[priority].enqueue(element);
        size++;
    }
    E min(){
        if(size ==0)
            throw runtime_error("Queue is empty.");
        for(int i =0; i < priorities; i++){
            if(!queues[i].isEmpty())
                return queues[i].frontValue();
        }
        throw runtime_error("Queue not found.");
    }
    E removeMin(){
        if(size ==0)
            throw runtime_error("Queue is empty.");
        for(int i =0; i < priorities; i++){
            if(!queues[i].isEmpty()){
                size--;
                return queues[i].dequeue();
            }
        }
        throw runtime_error("Queue not found.");
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    void print(){
        for(int i = 0; i < priorities; i++){
            queues[i].print();
        }
    }
};

#endif // LINKEDPRIORITYQUEUE_H
