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
      f = f -> next;
    }
}

class LinkedQueue{
public:
    int n;
    LinkedList* ls;
    LinkedQueue();
    int size();
    int isEmpty();
    void front();
    void rear();
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

void LinkedQueue::front() {
    if(isEmpty()){
        cout << "Empty\n";
    } else {
        cout << ls->front() << "\n";
    }
}

void LinkedQueue::rear() {
    if(isEmpty()){
        cout << "Empty\n";
    } else {
        cout << ls->end() << "\n";
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
        cout << ls->front() <<"\n";
        ls->removeFront();
        n--;
    }
}


int main() {
    int S,N,X;
    string cmd;
    cin >> S;
    cin >> N;
    LinkedQueue que;
    while(N--) {
        cin >> cmd;
        if (cmd == "enqueue") {
            cin >> X;
            if (que.size() == S){
                cout << "FULL\n";
            }else {
                que.enqueue(X);
            }
        } else if (cmd == "size"){
            cout << que.size() << "\n";
        } else if (cmd == "isEmpty"){
            cout << que.isEmpty() << "\n";
        } else if (cmd == "dequeue") {
            que.dequeue();
        } else if (cmd == "front"){
            que.front();
        } else if (cmd == "rear") {
            que.rear();
        }
    }
}