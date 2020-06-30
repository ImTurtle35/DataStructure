#include <iostream>
#include <string>
using namespace std;

typedef string Elem;

class StringNode{
private:
  Elem elem;
  StringNode* next;
  
  friend class StringLinkedList;
};

class StringLinkedList{
private:
  StringNode* head;
  StringNode* tail;
public:
  StringLinkedList();
  ~StringLinkedList();
  bool empty() const;
  Elem front() const;
  void addFront(const Elem& e);
  void removeFront();
  void addBack(const Elem& e);
  void removeBack();
};

void StringLinkedList::addFront(const Elem& e){
    StringNode* v = new StringNode;
    if(empty()){
        tail = v;
    }
    v->elem = e;
    v->next = head;
    head = v;
}

void StringLinkedList::addBack(const Elem& e){
    StringNode* v = new StringNode;
    v->elem = e;
    v->next = NULL;
    if(empty()){
        head = tail = v;
    }
    else {
        tail->next = v;
        tail = v;
    }
}