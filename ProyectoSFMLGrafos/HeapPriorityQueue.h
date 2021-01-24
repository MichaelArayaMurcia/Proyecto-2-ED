#ifndef HEAPPRIORITYQUEUE_H
#define HEAPPRIORITYQUEUE_H
#include "KVpair.h"
#include "Minheap.h"
#include "priorityQueue.h"
#include <stdexcept>

using namespace std;

template <typename E>
class HeapPriorityQueue : public priorityQueue<E>{
private:
    Minheap<KVpair<int, E> > *elements;
    int priorities;

public:
    HeapPriorityQueue(int priorities, int max = DEFAULT_MAX_SIZE){
        if(priorities <=0) throw runtime_error("The number of priorities most be positive.");
        if(max <= 0) throw runtime_error("Invalid queue max size.");
        this->priorities = priorities;
        elements = new Minheap<KVpair<int, E> >(max);
    }
    ~HeapPriorityQueue(){
        delete elements;
    }

    void insert(E element, int priority){
        if(priority < 0 || priority >= priorities) throw runtime_error("Invalid priority.");
        KVpair<int, E> p(priority, element);
        elements->insert(p);
    }
    E min(){
        if(elements->getSize()==0) throw runtime_error("Queue is empty.");
        KVpair<int, E> p = elements->first();
        return p.getValue();
    }
    E removeMin(){
        if(elements->getSize()==0) throw runtime_error("Queue is empty.");
        KVpair<int, E> p = elements->removeFirst();
        return p.getValue();
    }
    int getSize(){
        return elements->getSize();
    }
    bool isEmpty(){
        return elements->getSize()==0;
    }
    int indexOf(E element){
        if(elements->getSize()==0) throw runtime_error("Queue is empty.");
        for(int i =0; i<elements->getSize();i++){
            KVpair<int,E> p = elements[i];
            if(p.getValue()== element){
                return i;
            }
        }
        return -1;
    }
    bool contains(E element){
        if(elements->getSize()==0) throw runtime_error("Queue is empty.");
        return indexOf(element) != -1;
    }
    E removeElement(E element){
        if(isEmpty()) throw runtime_error("Queue is empty.");
        if(!contains(element)) throw runtime_error("Element is not found.");
        KVpair<int,E> p = elements->remove(indexOf(element));
        return p.getValue();
    }
};

#endif // HEAPPRIORITYQUEUE_H
