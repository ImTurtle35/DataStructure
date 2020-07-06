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

class SLinkedList{
public:
  Node* head;
  Node* tail;

  SLinkedList() {
    head = NULL;
    tail = NULL;
  }

  void addFront(int x) {
    Node* newnode = new Node(x);
    if(empty()) {
      tail = newnode;
      head = newnode;
    }
    else {
      newnode -> next = head;
      head = newnode;
    }
  }

  void addBack(int x) {
    Node* newnode = new Node(x);
    if(empty()) {
      tail = newnode;
      head = newnode;
    }
    else {
      tail -> next = newnode;
      tail = newnode;
    }
  }

  void showList() {
    if(empty()) {
        cout << -1 << "\n";
    } else {
        Node* cur = head;
        while(cur != NULL) {
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
      Node* n = head -> next;
      int d = head-> data;
      delete(head);
      head = n;
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
  
};

int main() {
    int N,X;
    string s;
    SLinkedList sll;
    cin >> N;
    while(N--) {
        cin >> s;
        if(s == "empty") {
            cout << sll.empty() << "\n";
        } else if(s == "front") {
            cout << sll.front() << "\n";
        } else if (s == "removeFront") {
            cout << sll.removeFront() << "\n";
        } else if (s == "addFront") {
            cin >> X;
            sll.addFront(X);
        } else if (s == "addBack") {
            cin >> X;
            sll.addBack(X);
        } else if (s == "showList"){
            sll.showList();
        }
    }
}