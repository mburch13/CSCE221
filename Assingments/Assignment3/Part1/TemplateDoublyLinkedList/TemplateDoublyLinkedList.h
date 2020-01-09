#include <cstdlib>
#include <iostream>
using namespace std;
//class DoublyLinkedList; // class declaration

// extend range_error from <stdexcept>
struct EmptyDLinkedListException(std::range_error){
    explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg){};
    
};

// list node
template<class T>
struct DListNode {
    T obj;
    DListNode *prev, *next;
    DListNode(T e=T(), DListNode *p = NULL, DListNode *n = NULL)
    : obj(e), prev(p), next(n) {}
};

// doubly linked list
template<class T>
class DoublyLinkedList {
private:
    DListNode<T> header, trailer;
public:
    DoublyLinkedList<T>(); // constructor
    DoublyLinkedList<T>(const DoublyLinkedList<T>& dll); // copy constructor
    ~DoublyLinkedList<T>(); // destructor
    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& dll); // assignment operator
    // return the pointer to the first node
    DListNode<T> *getFirst() const { return header.next; }
    // return the pointer to the trailer
    const DListNode<T> *getAfterLast() const { return &trailer; }
    // return if the list is empty
    bool isEmpty() const { return header.next == &trailer; }
    T first() const; // return the first object
    T last() const; // return the last object
    void insertFirst(T newobj); // insert to the first of the list
    T removeFirst(); // remove the first node
    void insertLast(T newobj); // insert to the last of the list
    T removeLast(); // remove the last node
    void insertAfter(DListNode<T> &p, T newobj);
    void insertBefore(DListNode<T> &p, T newobj);
    T removeAfter(DListNode<T> &p);
    T removeBefore(DListNode<T> &p);
};

//constructor
template<class T>
DoublyLinkedList<T>::DoublyLinkedList(){
    header = DListNode<T>();
    trailer = DListNode<T>();
    header.next = &trailer;
    trailer.prev = &header;
}

// copy constructor
template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& dll)
{
    // Initialize the list
    header.next = &trailer;
    trailer.prev = &header;
    
    DListNode<T> *temp = dll.header.next;
    while(temp != dll.getAfterLast()){
        insertLast(temp->obj);
        temp = temp->next;
    }
    trailer = *temp;
    
}

// assignment operator
template<class T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& dll)
{
    // Delete the whole list
    
    if(this != &dll){
        DListNode<T> *temp = dll.header.next;
        while(temp != dll.getAfterLast()){
            insertLast(temp->obj);
            temp = temp->next;
        }
        trailer = *temp;
    }
    return *this;
}

// insert the new object as the first one
template<class T>
void DoublyLinkedList<T>::insertFirst(T newobj)
{
    DListNode<T> *newNode = new DListNode<T> (newobj, &header, header.next);
    header.next->prev = newNode;
    header.next = newNode;
}

// insert the new object as the last one
template<class T>
void DoublyLinkedList<T>::insertLast(T newobj)
{
    DListNode<T> *newNode = new DListNode<T>(newobj, trailer.prev, &trailer);
    trailer.prev->next = newNode;
    trailer.prev = newNode;
}

// remove the first object from the list
template<class T>
T DoublyLinkedList<T>::removeFirst()
{
    if(isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    DListNode<T> *node = header.next;
    node->next->prev = &header;
    header.next = node->next;
    T obj = node->obj;
    delete node;
    return obj;
}

// remove the last object from the list
template<class T>
T DoublyLinkedList<T>::removeLast()
{
    if(isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    DListNode<T> *node = trailer.prev;
    node->prev->next = &trailer;
    trailer.prev = node->prev;
    T obj = node->obj;
    delete node;
    return obj;
}

// destructor
template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    DListNode<T> *prev_node;
    DListNode<T> *node = header.next;
    while(node != &trailer){
        prev_node = node;
        node = node->next;
        delete prev_node;
    }
    header.next = &trailer;
    trailer.prev = &header;
}

// return the first object
template<class T>
T DoublyLinkedList<T>::first() const
{
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    return header.next->obj;
}

// return the last object
template<class T>
T DoublyLinkedList<T>::last() const
{
    if(isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    return trailer.prev->obj;
}

// insert the new object after the node p
template<class T>
void DoublyLinkedList<T>::insertAfter(DListNode<T> &p, T newobj)
{
    DListNode<T> *newNode = new DListNode<T>(newobj, &p, p.next);
    p.next=newNode;
    p.next->prev=newNode;
    
}

// insert the new object before the node p
template<class T>
void DoublyLinkedList<T>::insertBefore(DListNode<T> &p, T newobj)
{
    DListNode<T> *newNode = new DListNode<T>(newobj, p.prev, &p);
    p.prev->next=newNode;
    p.prev=newNode;
}

// remove the node after the node p
template<class T>
T DoublyLinkedList<T>::removeAfter(DListNode<T> &p)
{
    if (p.next == nullptr)
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    DListNode<T>* temp = p.next;
    T val = temp->obj;
    p.next = temp->next;
    temp->next = temp->prev;
    
    delete temp;
    return val;
}

// remove the node before the node p
template<class T>
T DoublyLinkedList<T>::removeBefore(DListNode<T> &p)
{
    if (p.prev == nullptr)
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    DListNode<T>* temp = p.prev;
    T val = temp->obj;
    temp->prev->next = &p;
    p.prev = temp->prev;
    delete temp;
    return val;
}

// return the list length
template<class T>
int TemplateDoublyLinkedListLength(DoublyLinkedList<T>& dll)
{
    DListNode<T> *current = dll.getFirst();
    int count = 0;
    while(current != dll.getAfterLast()){
        count++;
        current = current->next;
    }
    return count;
}

// output operator
template<class T>
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll)
{
    DListNode<T> *temp = dll.getFirst();
    while(temp != dll.getAfterLast() && temp != nullptr){
        out << temp->obj << " ";
        temp = temp->next;
    }
    return out;
}

