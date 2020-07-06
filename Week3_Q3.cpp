#include <iostream>
#include <string>
using namespace std;

class Node{
public:
  int data;
  Node* next;
  
  Node(int e){
    this->data = e;
    this->next = NULL;
  }
};

class CLinkedList{
public:
  Node* head;
  Node* tail;

  CLinkedList() {
    head = NULL;
    tail = NULL;
  }

  void addFront(int x) {
    Node* newnode = new Node(x);
    if(empty()) {
      tail = newnode;
      head = newnode;
      tail -> next = head;
      head -> next = tail;
    }
    else {
      newnode -> next = head;
      head = newnode;
      tail -> next = newnode;
    }
  }

  void addBack(int x) {
    Node* newnode = new Node(x);
    if(empty()) {
      tail = newnode;
      head = newnode;
      tail -> next = head;
      head -> next = tail;
    }
    else {
      tail -> next = newnode;
      tail = newnode;
      newnode -> next = head;
    }
  }

  void showList() {
    if(empty()) {
        cout << -1 << "\n";
    } else {
        Node* cur = head;
        cout << cur -> data << " ";
        cur = cur->next;
        while(cur != head) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << "\n";
    }
  }

  int removeFront() {
    if(empty()) {
      return -1;
    }
    else {
      Node* n = head;
      int d = head-> data;
      head = n->next;
      tail->next = head;
      delete(n);
      return d;
    }
  }

  int front() {
    if(empty()) {
      return -1;
    }
    else {
      return head->data;
    }
  }

  int empty() {
    if(head==NULL){
      return 1;
    }
    else{
      return 0;
    }
  }
  
  void deleteNode(int x, int c) {
    Node* before = head;
    if(empty()){

    }
    else {
    if(x == 0) {
        removeFront();
    }
    else if (x == c) {
      while(before->next != tail) {
        before = before->next;
      }
      before -> next = head;
      tail = before;

    }
    else {
        for(int i{0}; i < x-1; i++) {
            before = before->next;
        }
        Node* dn = before->next;
        before->next = dn->next;
        delete(dn);
    }
    }
  }
};

int main() {
    int N,X;
    string s;
    cin >> N;
    while(N--) {
        CLinkedList cll;
        int count = 10;
        for(int i{0}; i < count; i++) {
            cin >> X;
            cll.addBack(X);
        }
        for(int i{0}; i < 3; i++) {
            cin >> s >> X;
            X %= count;
            count--;
            cll.deleteNode(X,count);
        }
        cll.showList();
    }
}