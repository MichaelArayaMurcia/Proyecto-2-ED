#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "list.h"
#include "node.h"
#include <cstdlib>

using namespace std;
template <typename E>
class Linkedlist : public list<E>{
private:
    Node<E>* head;
    Node<E>* tail;
    Node<E>* current;
    int size;

public:
    Linkedlist(){
        tail=current=head=new Node<E>();
        size=0;
    }
    ~Linkedlist(){
        clear();
        delete head;
    }
    void insert(E element){
        current->setNext(new Node<E>(element, current->getNext()));
        if(tail==current){
            tail = current->getNext();
        }
        size++;
    }
    void append(E element){
        tail->setNext(new Node<E>(element));
        tail = tail->getNext();
        size++;
    }
    E remove(){
        if(size==0) throw runtime_error("List is empty.");
        if(current->getNext()==nullptr) throw runtime_error("No current element.");
        E result = current->getNext()->getElement();
        Node<E>* temp = current->getNext();
        current->setNext(temp->getNext());
        if (temp == tail) tail =current;
        delete temp;
        size--;
        return result;
    }
    void clear(){
        current = head->getNext();
        while(current != nullptr){
            head->setNext(current->getNext());
            delete current;
            current=head->getNext();
        }
        current=tail=head;
        size =0;
    }
    E getElement(){
        if(size==0)
            throw runtime_error("List is empty.");
        if(current->getNext()==nullptr)
            throw runtime_error("No current element.");
        return current->getNext()->getElement();
    }
    void gotoStart(){
        current = head;
    }
    void gotoEnd(){
        current = tail;
    }
    void gotoPos(int pos){
        if (pos <0 || pos>size)
            throw runtime_error("Index out of bounds.");
        current = head;
        for(int i=0; i <pos;i++){
            current = current->getNext();
        }
    }
    void next(){
        if(current != tail){
            current = current->getNext();
        }
    }
    void previous(){
        if (current != head){
            Node<E>* temp = head;
            while(temp->getNext() != current){
                temp = temp->getNext();
            }
            current = temp;
        }
    }
    bool atStart(){
        return current == head;
    }
    bool atEnd(){
        return current == tail;
    }
    int getPos(){
        int pos =0;
        for(Node<E> *temp = head; temp != current; temp = temp->getNext()){
            pos++;
        }
        return pos;
    }
    int getSize(){
        return size;
    }
};

#endif // LINKEDLIST_H
