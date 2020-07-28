#include <iostream>
#include <vector>

using namespace std;

class Node{
public:
    int data;
    Node* parent;
    Node* rChild;
    Node* lChild;

    Node() {
        this->data = NULL;
        this->parent = NULL;
        this->rChild = NULL;
        this->lChild = NULL;
    }
    Node(int data) {
        this->data = data;
        this->parent = NULL;
        this->rChild = NULL;
        this->lChild = NULL;
    }
    ~Node(){}
    void insertlChilde(Node* lChild){
        this->lChild = lChild;
        lChild->parent = this;
    }
    void insertrChild(Node* rChild){
        this->rChild = rChild;
        rChild->parent = this;
    }
    void printDegree(){
        int ans = 0;
        if(this->rChild != NULL) ans++;
        if(this->lChild != NULL) ans++;
        cout << ans << "\n";
    }
    void printDepth() {
        int depth = 0;
        Node* curnode = this;
        while(curnode->parent != NULL) {
            depth++;
            curnode = curnode -> parent;
        }
    }
};

class BST{
public:
    Node* root;
    int height;
    BST(){
        root = NULL;
        height = 0;
    }
    ~BST(){
        this->treeDestructor(this->root);
    }
    void insertNode(int data) {
        int height = 0;
        Node* newnode = new Node(data);
        if(root == NULL) {
            root = newnode;
        }
        else {
            Node*tmp = root;
            while(tmp != NULL) {
                if(tmp->data <= data)
                   tmp = tmp->rChild;
                else
                   tmp = tmp->lChild;
            }
            newnode->parent = tmp->parent;
            if(tmp->parent->rChild == tmp){
                tmp->parent->rChild = newnode;
            } else {
                tmp->parent->lChild = newnode;
            }
        }
    }
    Node* findNode(int data) {
        Node* tmp = root;
        while(tmp != NULL) {
            if(tmp->data == data)
                return tmp;
            else {
                if(tmp->data < data)
                   tmp = tmp->rChild;
                else
                   tmp = tmp->lChild;
            }
        }
        return NULL;
    }
    int printHeight(Node* node){
        Node* tmp = node;
        int a = 0,b = 0;
        if(node->lChild != NULL)
           int a = 1+printHeight(node->lChild);
        if(node->rChild != NULL)
           int b = 1+printHeight(node->rChild);
        if(a >= b) return a;
        else return b;
    }
    void deleteNode(int data) {
        Node* trash = findNode(data);
        if(trash->lChild == NULL && trash->rChild == NULL){
            if(trash->parent->rChild == trash) {
                trash->parent->rChild = NULL;
            }
            else {
                trash->parent->lChild = NULL;
            }
            delete(trash);
        }
        else if(trash->lChild == NULL || trash->rChild == NULL){
            Node* tmp;
            if(trash->rChild == NULL){
                tmp = trash->lChild;
            } else {
                tmp = trash->rChild;
            }
            if(trash->parent->rChild == trash) {
                trash->parent->rChild = tmp;
                tmp->parent = trash->parent;
            }
            else {
                trash->parent->lChild = tmp;
                tmp->parent = trash->parent;
            }
            delete(trash);
        }
        else{
            Node* tmp = findMinimum(trash->rChild);
            if(tmp->parent->lChild == tmp) {
                tmp->parent->lChild = NULL;
            } else {
                tmp->parent->rChild = NULL;
            }
            trash->data = tmp->data;
            delete(tmp);
        }
    }
    Node* findMinimum(Node* node) {
        Node* tmp = node;
        while(tmp->lChild != NULL) {
            tmp = tmp->lChild;
        }
        return tmp;
    }
    void printPreorderTraversal(Node* root){
        cout << root->data << " ";
        printPreorderTraversal(root->lChild);
        printPreorderTraversal(root->rChild);
    }
    void treeDestructor(Node* root) {
        if(root == NULL)
            return;
        if(root->rChild != NULL)
           this->treeDestructor(root->rChild);
        if(root->lChild != NULL)
           this->treeDestructor(root->lChild);
        delete(root);
    }
};