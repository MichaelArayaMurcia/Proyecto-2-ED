#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include "node.h"
#include "Queue.h"
#include <stdexcept>

using namespace std;
template <typename E>
class Linkedqueue:public Queue<E>{
private:
    Node<E> *front;
    Node<E> *rear;
    int size;
public:
    Linkedqueue(){
        front=rear=new Node<E>();
        size=0;
    }
    ~Linkedqueue(){
        clear();
        delete rear;
    }
    void enqueue(E element){
        rear->set(new Node<E>(element));
        rear=rear->getNext();
        size++;
    }
    E dequeue(){
        if(size==0)
            throw runtime_error("Queue is empty.");
        E res=front->getNext()->getElement();
        Node<E> *temp=front->getNext();
        front->setNext(temp->getNext());
        delete temp;
        if(size==1)
            rear=front;
        size--;
        return res;
    }
    E frontValue(){
        if(size ==0)
            throw runtime_error("Queue is empty.");
        return front->getNext()->getElement();
    }
    void clear(){
        rear=front->getNext();
        while(rear!=nullptr){
            front->setNext(rear->getNext());
            delete rear;
            rear = front->getNext();
        }
        rear = front;
        size=0;
    }
    bool isEmpty(){
        return size==0;
    }
    int getSize(){
        return size;
    }
};

#endif // LINKEDQUEUE_H
