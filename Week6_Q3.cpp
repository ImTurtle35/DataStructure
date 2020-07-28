#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    Node(int data);
    int data;
    Node* next;
};
Node::Node(int data){
    this->data = data;
    this->next = NULL;
}

class LinkedList{
public:
    Node* f;
    Node* r;
    LinkedList();
    int front();
    int end();
    void addEnd(int data);
    void removeFront();
};
LinkedList::LinkedList(){
    f = NULL; r = NULL;
}
int LinkedList::front(){
    return f->data;
}
int LinkedList::end(){
    return r->data;
}
void LinkedList::addEnd(int data) {
    Node* newNode = new Node(data);
    if(f == NULL) {
        r = newNode; f = newNode;
    } else {
        r->next = newNode;
        r = newNode;
    }
}
void LinkedList::removeFront() {
    if(f==NULL){

    } else {
      Node* tn = f;
      f = f -> next;
      delete(tn);
    }
}

class LinkedQueue{
public:
    int n;
    LinkedList* ls;
    LinkedQueue();
    int size();
    int isEmpty();
    int front();
    int rear();
    void enqueue(int e);
    void dequeue();
};
LinkedQueue::LinkedQueue() {
    n = 0; ls = new LinkedList();
}
int LinkedQueue::size() {
    return n;
}
int LinkedQueue::isEmpty() {
    if(n == 0){
        return 1;
    } else {
        return 0;
    }
}
int LinkedQueue::front() {
    if(isEmpty()){
        cout << "Empty";
        return -1;
    } else {
        return ls->front();
    }
}
int LinkedQueue::rear() {
    if(isEmpty()){
        cout << "Empty";
        return -1;
    } else {
        return ls->end();
    }
}
void LinkedQueue::enqueue(int e) {
    ls->addEnd(e);
    n++;
}
void LinkedQueue::dequeue() {
    if(isEmpty()) {
        cout << "Empty\n";
    } else{
        n--;
        ls->removeFront();
    }
}

int main() {
    int T, N, x, y;
    LinkedQueue P1;
    LinkedQueue P2;
    cin >> T;
    while(T--) {
        cin >> N;
        int p1s = 0; int p2s = 0;
        int p1lft = 0; int p2lft = 0;
        for(int i{0}; i < N; i++) {
            cin >> x;
            P1.enqueue(x);
        }
        for(int i{0}; i < N; i++) {
            cin >> y;
            P2.enqueue(y);
        }
        while(!P1.isEmpty()){
            int p1_h = P1.front() + p1lft; int p2_h = P2.front() + p2lft;
            P1.dequeue(); P2.dequeue();
            if(p1_h > p2_h) {
                p1s++;
                p1lft = p1_h - p2_h - 1;
                p2lft = 0;
            } else if (p1_h < p2_h) {
                p2s++;
                p2lft = p2_h - p1_h - 1;
                p1lft = 0;
            } else {
                p1lft = 0; p2lft=0;
            }
        }
        if(p1s > p2s) {
            cout << 1 <<"\n";
        } else if (p1s < p2s) {
            cout << 2 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
}