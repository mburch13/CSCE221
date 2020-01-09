//
//  MinQueue.cpp
//
//  Created by McKenzie on 7/27/18.
//

#include <stdio.h>
#include "DoublyLinkedList"

class MinQueue(){
private:
    DoublyLinkedList dll;
public:
    MinQueue() : dll() {}   //constructor
    ~MinQueue() {dll.~DoublyLinkedList(); } //destrucot
    void enqueue(int x) {ll.insertLast(x);}
    void dequeue() throw(QueueEmptyException);
    int size() const { return count; }
    bool isEmpty() const {ll.insertLast(elem)};
    int min();
};

void MinQueue::dequeue() throw(QueueEmptyException){
    if( isEmpty() )
        throw QueueEmptyException("Access to an empty queue");
    return ll.removeFirst();
}

int MinQueue::min(){
    int min;
    DListNode *temp;
    while(head.next != NULL){
        min = temp->elem;
        if(temp->next->elem < min){
            min = temp->next->elem;
        }
    }
    return min;
}
