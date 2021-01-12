#ifndef DNODE_H
#define DNODE_H

template <typename E>
class Dnode{
private:
    E element;
    Dnode<E> *next;
    Dnode<E> *previous;

public:
    Dnode(E element, Dnode<E> *next, Dnode<E> *previous){
        this->element=element;
        this->next=next;
        this->previous=previous;
    }
    Dnode(Dnode<E> *next = nullptr, Dnode<E> *previous = nullptr){
        this->next=next;
        this->previous=previous;
    }

    E getElement(){
        return element;
    }
    void setElement(E element){
        this->element=element;
    }
    Dnode<E> *getNext(){
        return next;
    }
    void setNext(Dnode<E> *next){
        this->next=next;
    }
    Dnode<E> *getPrevious(){
        return previous;
    }
    void setPrevious(Dnode<E> *previous){
        this->previous=previous;
    }

};

#endif // DNODE_H
