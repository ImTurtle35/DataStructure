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
        this->data = 0;
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
    ~Node(){ this-> data = NULL;}
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
        cout << ans << " ";
    }
    void printDepth() {
        int depth = 0;
        Node* curnode = this;
        while(curnode->parent != NULL) {
            depth++;
            curnode = curnode -> parent;
        }
        cout << depth << "\n";
    }
};

class BST{
public:
    Node* root;
    int height;
    BST(){
        root = NULL;
        height = -1;
    }
    ~BST(){
        this->treeDestructor(this->root);
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
                   if(tmp->rChild == NULL){
                       tmp->rChild = newnode;
                       newnode->parent = tmp;
                       break;
                   }
                   tmp = tmp->rChild;
                }
                else{
                    if(tmp->lChild == NULL) {
                       tmp->lChild = newnode;
                       newnode->parent = tmp;
                       break;
                    }
                   tmp = tmp->lChild;
                }
            }
            if(height > this->height){
                this->height = height;
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
    void printHeight(){
        cout << height << "\n";
    }

    void transPlant(Node* u, Node* v) {
        if(u->parent == NULL)
            this->root = v;
        else if (u == u->parent->lChild)
            u->parent->lChild = v;
        else 
            u->parent->rChild = v;
        if(v != NULL)
            v->parent = u->parent;
    }

    void deleteTree(int data) {
        Node* trash = findNode(data);
        if(trash == NULL) return;
        if(trash->lChild == NULL)
            transPlant(trash, trash->rChild);
        else if (trash->rChild == NULL)
            transPlant(trash, trash->lChild);
        else {
            Node* minnode = findMinimum(trash->rChild);
            if(minnode->parent != trash) {
                transPlant(minnode, minnode->rChild);
                minnode->rChild = trash->rChild;
                minnode->rChild->parent = minnode;
            }
            transPlant(trash, minnode);
            minnode->lChild = trash->lChild;
            minnode->lChild->parent = minnode;
        }
        delete(trash);
        trash = NULL;
    }
    Node* findMinimum(Node* node) {
        Node* tmp = node;
        while(tmp->lChild != NULL) {
            tmp = tmp->lChild;
        }
        return tmp;
    }
    void printPreorderTraversal(Node* root){
        if(this->root == NULL) {
            cout << 0;
            return;
        }
        if(root == NULL) return;
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
        root = NULL;
    }
};

int main(){
    int T, N, M, input;
    cin >> T;
    while(T--){
        BST bst;
        cin >> N;
        while(N--){
            cin >> input;
            bst.insertNode(input);
        }
        cin >> M;
        while(M--) {
            cin >> input;
            bst.deleteTree(input);
        }
        bst.printPreorderTraversal(bst.root);
        cout << "\n";
    }
    return 0;
}