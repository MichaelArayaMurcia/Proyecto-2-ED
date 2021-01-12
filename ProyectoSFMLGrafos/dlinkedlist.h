#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
#include "dnode.h"
#include "list.h"
#include <stdexcept>

using namespace std;

template <typename E>
class Dlinkedlist:public list<E>{
private:
    Dnode<E> *head;
    Dnode<E> *current;
    Dnode<E> *tail;
    int size;
public:
    Dlinkedlist(){
       current = head = new Dnode<E>();
       head->setNext(tail = new Dnode<E>(nullptr, head));
       size = 0;
    }
    ~Dlinkedlist(){
        clear();
        delete head; delete tail;
    }
    void insert(E element){
        current->getNext()->setPrevious(new Dnode<E>(element, current->getNext(), current));
        current->setNext(current->getNext()->getPrevious());
        size++;
    }
    void append(E element){
        tail->getPrevious()->setNext(new Dnode<E>(element, tail, tail->getPrevious()));
        tail->setPrevious(tail->getPrevious()->getNext());
        size++;
    }
    E remove(){
        if(size ==0){
            throw runtime_error("List is empty.");
        }
        if(current->getNext() == tail){
            throw runtime_error("No current element.");
        }
        E res = current->getNext()->getElement();
        current->setNext(current->getNext()->getNext());
        delete current->getNext()->getPrevious();
        current->getNext()->setPrevious(current);
        size--;
        return res;
    }
    void clear(){
        current= head->getNext();
        while(current != tail){
            head->setNext(current->getNext());
            delete current;
            current=head->getNext();
        }
        tail->setPrevious(head);
        current = head;
        size =0;
    }
    E getElement(){
        if(size == 0){
                throw runtime_error("List is empty.");
        }
        if(current->getNext() == tail){
            throw runtime_error("No current element.");
        }
        return current->getNext()->getElement();
    }
    void gotoStart(){
        current = head;
    }
    void gotoEnd(){
        current = tail->getPrevious();
    }
    void gotoPos(int pos){
        if(pos<0||pos>size){
            throw runtime_error("Index out of range.");
        }
        current = head;
        for(int i=0;i<pos;i++){
            current = current->getNext();

        }
    }
    void next(){
        if(current->getNext()!= tail){
            current = current->getNext();
        }
    }
    void previous(){
        if(current != head){
            current = current->getPrevious();
        }
    }
    bool atStart(){
        return current==head;
    }
    bool atEnd(){
        return current==tail->getPrevious();
    }
    int getPos(){
        Dnode<E>* temp = head;
        int pos = 0;
        while (temp != current){
            pos++;
            temp = temp->getNext();
        }
        return pos;
    }
    int getSize(){
        return size;
    }
};

#endif // DLINKEDLIST_H
