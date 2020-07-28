#include <iostream>
#include <vector>

using namespace std;

class Node{
public:
    int data;
    Node* par;
    Node* lc;
    Node* rc;

    Node(int data){
        this->data = data;
        this->par = NULL;
        this->lc = NULL;
        this->rc = NULL;
    }

    Node(){
        this->data = NULL;
        this->par = NULL;
        this->lc = NULL;
        this->rc = NULL;
    }
    
    ~Node(){};

    void insertlChilde(Node* lChild){
        this->lc = lChild;
        lChild->par = this;
    }
    void insertrChild(Node* rChild){
        this->rc = rChild;
        rChild->par = this;
    }
    void printDegree(){
        int ans = 0;
        if(this->rc != NULL) ans++;
        if(this->lc != NULL) ans++;
        cout << ans << " ";
    }
    void printDepth() {
        int depth = 0;
        Node* curnode = this;
        while(curnode->par != NULL) {
            depth++;
            curnode = curnode -> par;
        }
        cout << depth << "\n";
    }
};

class BST {
public:
    Node* root;
    int height;

    BST() {
        root = NULL;
        height = -1;
    }

    void insertNode(int data) {
        int height = 0;
        Node* newnode = new Node(data);
        if(root == NULL) {
            root = newnode;
            this->height = 0;
        }
        else {
            Node*tmp = root;
            while(tmp != NULL) {
                height++;
                if(tmp->data <= data){
                   if(tmp->rc == NULL){
                       tmp->rc = newnode;
                       newnode->par = tmp;
                       break;
                   }
                   tmp = tmp->rc;
                }
                else{
                    if(tmp->lc == NULL) {
                       tmp->lc = newnode;
                       newnode->par = tmp;
                       break;
                    }
                   tmp = tmp->lc;
                }
            }
            if(height > this->height){
                this->height = height;
            }
        }
    }

    void deleteNode()
};