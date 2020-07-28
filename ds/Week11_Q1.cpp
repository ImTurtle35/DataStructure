#include <iostream>
#include <vector>
#include <string>

using namespace std;

class node{
public:
    int data;
    node* par;
    node* lchild;
    node* rchild;
    node(int data) {
        this->data = data;
        this->lchild = NULL;
        this->rchild = NULL;
        this->par = NULL;
    }
    node() {
        this->data = NULL;
        this->lchild = NULL;
        this->rchild = NULL;
        this->par = NULL;
    }
    ~node(){}
    void insertlChild(node* lchild) {
        this->lchild = lchild;
        lchild->par = this;
    }
    void insertrChild(node* rchild) {
        this->rchild = rchild;
        rchild->par = this;
    }
    void printDegree() {
        int degree = 0;
        if(this->rchild != NULL) degree++;
        if(this->lchild !=NULL) degree++;
        cout << degree <<" ";
    }
};

class BST{
public:
    node* root;
    int height;
    BST(){
        height = 0;
        root = NULL;
    }
    ~BST(){this->treeDestructor(this->root);}
    void treeDestructor(node* root){
        if(root == NULL) return;
        if(this->root == NULL) {
            return;
        }
        if(root->lchild)treeDestructor(root->lchild);
        if(root->rchild)treeDestructor(root->rchild);
        delete(root);
        root = NULL;
    }
    void insertNode(int data) {
        node* newnode = new node(data);
        if(root == NULL){
            root = newnode;
            this->height = 0;
        }
        else {
            node* tmp = root;
            while(tmp != NULL) {
                height++;
                if(tmp->data <= data) {
                    if(tmp->rchild == NULL) {
                        tmp->rchild = newnode;
                        newnode->par = tmp;
                        break;
                    }
                    tmp = tmp->rchild;
                }
                else {
                    if(tmp->lchild == NULL) {
                        tmp->lchild = newnode;
                        newnode->par = tmp;
                        break;
                    }
                    tmp = tmp->lchild;
                }
                if(height > this->height) {
                    this->height = height;
                }
            }
        }
    }
    node* findNode(int data) {
        if(root == NULL) {
            cout << 0 << "\n";
            return NULL;
        }
        node* tmp = root;
        while(tmp != NULL) {
            if(tmp->data == data) {
                return tmp;
            }
            else if(tmp->data < data) {
                tmp = tmp->rchild;
            }
            else if (tmp->data > data) {
                tmp = tmp->lchild;
            }

        }
        cout << 0 << "\n";
        return NULL;
    }
};

int main() {
    int T, N, M, input;
    cin >> T;
    while(T--) {
        BST bst;
        cin >> N;
        for(int i{0}; i < N; i++) {
            cin >> input;
            bst.insertNode(input);
        }
        cin >> M;
        for(int i{0}; i < M; i++) {
            cin >> input;
            node* tmp = bst.findNode(input);
            if(tmp) {
                tmp->printDegree();
            }
        }
    }
}