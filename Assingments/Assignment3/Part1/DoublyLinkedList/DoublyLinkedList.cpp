#include "DoublyLinkedList.h"
#include <stdexcept>

// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};

// copy constructor
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& dll)
{
  // Initialize the list
    header.next = &trailer;
    trailer.prev = &header;
  
    DListNode *temp = dll.header.next;
    while(temp != dll.getAfterLast()){
        insertLast(temp->obj);
        temp = temp->next;
    }
}

// assignment operator
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& dll)
{
  // Delete the whole list

    if(this != &dll){
        DListNode *temp = dll.header.next;
        while(temp != dll.getAfterLast()){
            insertLast(temp->obj);
            temp = temp->next;
        }
    }
    return *this;
}

// insert the new object as the first one
void DoublyLinkedList::insertFirst(int newobj)
{ 
    DListNode *newNode = new DListNode (newobj, &header, header.next);
    header.next->prev = newNode;
    header.next = newNode;
}

// insert the new object as the last one
void DoublyLinkedList::insertLast(int newobj)
{
    DListNode *newNode = new DListNode(newobj, trailer.prev, &trailer);
    trailer.prev->next = newNode;
    trailer.prev = newNode;
}

// remove the first object from the list
int DoublyLinkedList::removeFirst()
{ 
    if(isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    DListNode *node = header.next;
    node->next->prev = &header;
    header.next = node->next;
    int obj = node->obj;
    delete node;
    return obj;
}

// remove the last object from the list
int DoublyLinkedList::removeLast()
{
    if(isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    DListNode *node = trailer.prev;
    node->prev->next = &trailer;
    trailer.prev = node->prev;
    int obj = node->obj;
    delete node;
    return obj;
}

// destructor
DoublyLinkedList::~DoublyLinkedList()
{
    DListNode *prev_node, *node = header.next;
    while(node != &trailer){
        prev_node = node;
        node = node->next;
        delete prev_node;
    }
    header.next = &trailer;
    trailer.prev = &header;
}

// return the first object
int DoublyLinkedList::first() const
{ 
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    return header.next->obj;
}

// return the last object
int DoublyLinkedList::last() const
{
    if(isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    return trailer.prev->obj;
}

// insert the new object after the node p
void DoublyLinkedList::insertAfter(DListNode &p, int newobj)
{
    DListNode *newNode = new DListNode(newobj, &p, p.next);
    p.next=newNode;
    p.next->prev=newNode;
}

// insert the new object before the node p
void DoublyLinkedList::insertBefore(DListNode &p, int newobj)
{
    DListNode *newNode = new DListNode(newobj, p.prev, &p);
    p.prev->next=newNode;
    p.prev=newNode;
}

// remove the node after the node p
int DoublyLinkedList::removeAfter(DListNode &p)
{
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    DListNode* temp = p.next;
    temp->prev = temp->next;
    temp->next = temp->prev;
    delete temp;
    return temp->obj;
}

// remove the node before the node p
int DoublyLinkedList::removeBefore(DListNode &p)
{
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    DListNode* temp = p.prev;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    return temp->obj;
}

// return the list length
int DoublyLinkedListLength(DoublyLinkedList& dll)
{
    DListNode *current = dll.getFirst();
    int count = 0;
    while(current != dll.getAfterLast()){
        count++;
        current = current->next;
    }
    return count;
}

// output operator
ostream& operator<<(ostream& out, const DoublyLinkedList& dll)
{
    DListNode *temp = dll.getFirst();
    while(temp != NULL){
        out << temp->obj << " ";
        temp = temp->next;
    }
  return out;
}
