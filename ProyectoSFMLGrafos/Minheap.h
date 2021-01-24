#ifndef MINHEAP_H
#define MINHEAP_H
#define DEFAULT_MAX_SIZE 1024
#include <stdexcept>
#include <iostream>
#include <math.h>

using namespace std;
template <typename E>
class Minheap{
private:
    E* elements;
    int max;
    int size;

    int leftChild(int n){
        return 2*n +1;
    }
    int rightChild(int n){
        return 2*n+2;
    }
    int parent(int n){
        if(n == 0)
            return -1;
        return (n-1) / 2;
    }
    void siftUp(int n){
        while(n >0 && elements[n] < elements[parent(n)]){
            swap(n, parent(n));
            n = parent(n);
        }
    }
    void swap(int n1, int n2){
        E temp = elements[n1];
        elements[n1]=elements[n2];
        elements[n2]=temp;
    }
    void siftDown(int n){
        while(!isLeaf(n) && elements[n] > elements[greaterChild(n)] ){
            int gChild = greaterChild(n);
            swap(n, gChild);
            n = gChild;
        }
    }
    bool isLeaf(int n){
        return leftChild(n) >= size;
    }
    int greaterChild(int n){
        if(rightChild(n)>= size || elements[leftChild(n) < rightChild(n) ]){
            return leftChild(n);
        }
        return rightChild(n);
    }

public:
    Minheap(int max = DEFAULT_MAX_SIZE){
        if(max <= 0)
            throw runtime_error("Invalid heap max size.");
        elements = new E[max];
        size =0;
        this->max=max;
    }
    ~Minheap(){
        delete []elements;
    }
    void insert(E element){
        if(size == max)
            throw runtime_error("Heap is full.");
        elements[size]=element;
        siftUp(size);
        size++;
    }
    E removeFirst(){
        if(size==0)
            throw runtime_error("Heap is empty.");
        return remove(0);
    }
    E remove(int pos){
        if(pos < 0 || pos >= size)
            throw runtime_error("Index out of range.");
        E result = elements[pos];
        swap(pos, size-1);
        size--;
        if(size>1) siftDown(pos);
        return result;
    }
    E first(){
        if(size == 0) throw runtime_error("Heap is empty.");
        return elements[0];
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    E getValue(int i){
        return elements[i];
    }
    int indexOf(E element){
        if(isEmpty()) throw runtime_error("Heap is empty.");
        for(int i = 0; i < size; i++){
            if(elements[i]==element) return i;
        }
        return -1;
    }
    bool contains(E element){
        if(isEmpty()) throw runtime_error("Heap is empty.");
        return indexOf(element) != -1;
    }
    E removeElement(E element){
        if(isEmpty()) throw runtime_error("Heap is empty.");
        if(!contains(element)) throw runtime_error("Element is not found.");
        E temp = remove(indexOf(element));
        return temp;
    }
    void merge(Minheap<E> *heap){
        for(int i =0; i < heap->getSize(); i++){
            E temp = heap->getValue(i);
            insert(temp);
        }
    }
    void print(){
        for(int i = 0; i < log2(size); i++){
            cout<<"Nivel "<<i<<": ";
            for(int j =0; j < pow(2,i); j++){
                int temp = pow(2,i);
                if(((j-1)+temp) < size) cout<<elements[(j-1)+temp]<<"-";
            }
            cout<<endl;
        }
    }
};

#endif // MINHEAP_H
