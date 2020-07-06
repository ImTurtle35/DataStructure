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

class linkedStack {
public:
    int n;
    SLinkedList* S;
    
    linkedStack() {
        this->S = new SLinkedList();
        this->n = 0;
    }
    int size() {
        return n;
    }
    bool empty() {
        if(n == 0)
           return 1;
        return 0;
    }
    int top() {
        if(empty()){
            return -1;
        }else {
            return S->front();
        }
    }
    void push(int e) {
        S->addFront(e);
        n++;
    }
    int pop() {
        if(empty()){
            return -1;
        }else {
            n--;
            return S->removeFront();
        }
    }
};


int main() {
    int N;
    string s;
    cin >> N;
    while(N--) {
        cin >> s;
        linkedStack ls;
        for(int i{0}; i < s.length(); i++) {
            char c = s[i];
            if(c >= '1' && c <= '9' ){
                ls.push(c - '0');
            }
            else if(c == '+') {
                int a = ls.pop(); int b = ls.pop();
                ls.push(a+b);
            }
            else if (c == '-'){ 
                int a = ls.pop(); int b = ls.pop();
                ls.push(b-a);
            }
            else if (c == '*'){
                int a = ls.pop(); int b = ls.pop();
                ls.push(b*a);
            }
            else {}
        }
        cout << ls.pop() << "\n";
    }
}