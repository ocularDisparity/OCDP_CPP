#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "Node.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

//////////////////////////////////////////////////////////////////////////////
//                         class template definition                        //
//////////////////////////////////////////////////////////////////////////////

template<typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList();
    DoublyLinkedList(T);
    DoublyLinkedList(const DoublyLinkedList<T>&);
    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>&);
    ~DoublyLinkedList();
    
    unsigned int size() const { return sz; }
    
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    
    void push_back(T);
    void push_front(T);
    
    void pop_back();
    void pop_front();
    
    void erase(unsigned int);
    void insert(T data, unsigned int idx);
    void clear();
    
    std::string to_str() const;
    // breaks encapsulation... gives operator== access to private data... not great approach, but makes the homework easier for you since we haven't talked about iterators :).
    template<typename U> friend bool operator==(DoublyLinkedList<U> const&, DoublyLinkedList<U> const&);
private:
    // do not change ordering.
    Node<T> *head;
    Node<T> *tail;
    unsigned int sz;
};

//////////////////////////////////////////////////////////////////////////////
//                       helper function declarations                       //
//////////////////////////////////////////////////////////////////////////////
template<typename T> std::ostream& operator<<(std::ostream &, DoublyLinkedList<T> const&);

template<typename T> bool operator==(DoublyLinkedList<T> const&, DoublyLinkedList<T> const&);

template<typename T> bool operator!=(DoublyLinkedList<T> const&, DoublyLinkedList<T> const&);

//////////////////////////////////////////////////////////////////////////////
//                     member template function definitions                 //
//////////////////////////////////////////////////////////////////////////////
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
  head = nullptr;
  tail = nullptr;
  sz = 0;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(T data)
{
  head = nullptr;
  tail = nullptr;
  sz = 0;
  
  Node<T> newNode = Node<T>(data);
  head = &newNode;
  tail = &newNode;
  sz += 1;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& originalList)
{
  /*
  // first node
  Node<T>* currentOriginal = originalList.head;
  T nodeData;
  
  if (currentOriginal != nullptr) {
    nodeData = currentOriginal->data;
    Node<T>* newNode = new Node<T>(nodeData);
    sz += 1;
    
    head = newNode;
    currentOriginal = currentOriginal->next;
    if (currentOriginal == nullptr) {
      tail = newNode;
    }
  } else {
    head = nullptr;
    tail = nullptr;
    sz = 0;
    return;
  }
  
  // consecutive nodes
  while(currentOriginal != nullptr) {
    nodeData = currentOriginal->data;
    push_back(nodeData);
    
    if (currentOriginal->next != nullptr) {
      currentOriginal = currentOriginal->next;
    } else {
      tail = currentOriginal;
      currentOriginal = currentOriginal->next;
    }
  }
  */
}

template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& originalList)
{
  /*
  clear();
  // first node
  Node<T>* currentOriginal = originalList.head;
  T nodeData;
  
  if (currentOriginal != nullptr) {
    nodeData = currentOriginal->data;
    Node<T>* newNode = new Node<T>(nodeData);
    sz += 1;
    
    head = newNode;
    currentOriginal = currentOriginal->next;
    if (currentOriginal == nullptr) {
      tail = newNode;
    }
  } else {
    head = nullptr;
    tail = nullptr;
    sz = 0;
    return *this;
  }
  
  // consecutive nodes
  while(currentOriginal != nullptr) {
    nodeData = currentOriginal->data;
    push_back(nodeData);
    
    if (currentOriginal->next != nullptr) {
      currentOriginal = currentOriginal->next;
    } else {
      tail = currentOriginal;
      currentOriginal = currentOriginal->next;
    }
  }
  
  return *this;
  */
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() 
{
  clear();
}

//////////////////////////////////////////////////////////////////////////////

template<typename T>
T& DoublyLinkedList<T>::front()
{
  T& frontData = head->data;
  
  return frontData;
}

template<typename T>
const T& DoublyLinkedList<T>::front() const
{
  const T& frontData = head->data;
  
  return frontData;
}

template<typename T>
T& DoublyLinkedList<T>::back()
{
  T& backData = tail->data;
  
  return backData;
}

template<typename T>
const T& DoublyLinkedList<T>::back() const
{
  const T& backData = tail->data;
  
  return backData;
}

//////////////////////////////////////////////////////////////////////////////

template<typename T>
void DoublyLinkedList<T>::push_back(T data)
{
  Node<T>* insert = new Node<T>(data);
  insert->prev = tail;
  if (tail != nullptr) {
    tail->next = insert;
  }
  if (tail == nullptr) {
    head = insert;
  }
	tail = insert;
  
  sz += 1;
}

template<typename T>
void DoublyLinkedList<T>::push_front(T data)
{
  Node<T>* insert = new Node<T>(data);
  insert->next = head;
  if (head != nullptr) {
    head->prev = insert;
  }
  if (head == nullptr) {
    tail = insert;
  }
  head = insert;
  
  sz += 1;
}

//////////////////////////////////////////////////////////////////////////////

template<typename T>
void DoublyLinkedList<T>::pop_back()
{
  Node<T>* newTail = tail->prev;
  if (newTail != nullptr) {
    delete tail;
    tail = newTail;
    tail->next = nullptr;
  } else {
    delete tail;
    tail = newTail;
    head = newTail;
  }
  sz -= 1;
}

template<typename T>
void DoublyLinkedList<T>::pop_front()
{
  Node<T>* newHead = head->next;
  if (newHead != nullptr) {
    delete head;
    head = newHead;
    head->prev = nullptr;
  } else {
    delete head;
    head = newHead;
    tail = newHead;
  }
  sz -= 1;
}

//////////////////////////////////////////////////////////////////////////////

template<typename T>
void DoublyLinkedList<T>::erase(unsigned int idx)
{
  if (idx >= sz) {
    return;
  }
  if (head == nullptr && tail == nullptr) {
    return;
  }
  
  Node<T>* erasePoint = head;
  for (unsigned int i = 0; i < idx; ++i) {
    erasePoint = erasePoint->next;
  }
  
  Node<T>* beforePoint = erasePoint->prev;
  Node<T>* afterPoint = erasePoint->next;
  
  if (beforePoint != nullptr && afterPoint != nullptr) {
    beforePoint->next = afterPoint;
    afterPoint->prev = beforePoint;
  } else if (beforePoint == nullptr && afterPoint != nullptr) {
    afterPoint->prev = nullptr;
    head = head->next;
  } else if (beforePoint != nullptr && afterPoint == nullptr) {
    beforePoint->prev = nullptr;
    tail = tail.prev;
  } else if (beforePoint == nullptr && afterPoint == nullptr) {
    head = nullptr;
    tail = nullptr;
  }
  
  delete erasePoint;
  
  sz -= 1;
}

template<typename T>
void DoublyLinkedList<T>::insert(T data, unsigned int idx)
{
  if (head == nullptr && tail == nullptr && idx == 0) {
    Node<T>* insert = new Node<T>(data);
    head = insert;
    tail = insert;
    insert->prev = nullptr;
    insert->next = nullptr;
    sz+= 1;
    return;
  }
  
  if (idx >= sz) {
    return;
  }
  
  Node<T>* afterPoint = head;
  for (unsigned int i = 0; i < idx; ++i) {
    afterPoint = afterPoint->next;
  }
  Node<T>* beforePoint = afterPoint->prev;
  
  Node<T>* insert = new Node<T>(data);
  
  if (beforePoint != nullptr && afterPoint != nullptr) {
    beforePoint->next = insert;
    afterPoint->prev = insert;
    
    insert->prev = beforePoint;
    insert->next = afterPoint;
  } else if (beforePoint == nullptr && afterPoint != nullptr) {
    afterPoint->prev = insert;
    head = insert;
    
    insert->prev = nullptr;
    insert->next = afterPoint;
  }
  
  sz += 1;
}

template<typename T>
void DoublyLinkedList<T>::clear() 
{
  // delete all nodes
  Node<T>* currentNode = head;
  Node<T>* nextNodeStorage;
  while(currentNode != nullptr) {
    nextNodeStorage = currentNode->next;
    delete currentNode;
    currentNode = nextNodeStorage;
  }
  
  // erase head, tail and size records
  head = nullptr;
  tail = nullptr;
  sz = 0;
}

//////////////////////////////////////////////////////////////////////////////

template<typename T>
std::string DoublyLinkedList<T>::to_str() const
{
    std::stringstream os;
    const Node<T> *curr = head;
    os << std::endl << std::setfill('-') << std::setw(80) << '-' << std::setfill(' ') << std::endl;
    os << "head: " << head << std::endl;
    os << "tail: " << tail << std::endl;
    os << "  sz: " << sz << std::endl;
    os << std::setw(16) << "node" << std::setw(16) << "node.prev" << std::setw(16) << "node.data" <<  std::setw(16) << "node.next" << std::endl;
    while (curr) {
        os << std::setw(16) << curr;
        os << std::setw(16) << curr->prev;
        os << std::setw(16) << curr->data;
        os << std::setw(16) << curr->next;
        os << std::endl;
        curr = curr->next;
    }
    os << std::setfill('-') << std::setw(80) << '-' << std::setfill(' ') << std::endl;
    return os.str();
}

//////////////////////////////////////////////////////////////////////////////
//                     helper template function definitions                 //
//////////////////////////////////////////////////////////////////////////////
template<typename T>
bool operator==(DoublyLinkedList<T> const& lhs, DoublyLinkedList<T> const& rhs)
{
    // getting you started on this once... definition for this overloaded operator will go here.
    return true;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, DoublyLinkedList<T> const& rhs)
{
    os << rhs.to_str();
    return os;
}

#endif