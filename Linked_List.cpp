#include <iostream>
#include <string>
using namespace std;

typedef int Elem;

class Node{
private:
  Elem elem;
  Node* next;

  friend class SLinkedList;
};

class SLinkedList{
private:
  Node* head;
  Node* tail;

public:
  SLinkedList();
  ~SLinkedList();
  bool empty() const;
  Elem front() const;
  void addFront(const Elem& e);
  void removeFront();
  void addBack(const Elem& e);
  void removeBack();
};

bool SLinkedList::empty() const{
  if(head == NULL){
    return 1;
  }else {
    return 0;
  }
}

Elem SLinkedList::front() const{
  if(empty()) {
    return -1;
  }else {
    
  }
}

void SLinkedList::addFront(const Elem& e) {
  Node* v = new Node;
  if(empty()) {
    tail = v;
  }
  v->elem = e;
  v->next = head;
  head = v;
}

void SLinkedList::removeFront() {
  if(empty()){
    return;
  }
  Node* old = head;
  head = old->next;
  delete old;
  if(empty()) {
    tail = NULL;
  }
}

void SLinkedList::addBack(const Elem& e) {
  Node* v = new Node;
  v -> elem = e;
  v -> next = NULL;
  if(empty()) {
    head = tail = v;
  }
  else {
    tail -> next = v;
    tail = v;
  }
}

void SLinkedList::removeBack() {
  if(empty()) return;
  Node* current = head;
  if(current == tail) {
    head = tail = NULL;
    delete current;
  }
  else {
    while(current -> next != tail) {
      current = current -> next;
    }
    tail = current;
    delete tail -> next;
    tail -> next = NULL;
  }
}