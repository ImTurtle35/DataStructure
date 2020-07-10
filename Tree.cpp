#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* par;
    std::vector<Node*> chi;

    Node() {
        this->data = NULL;
        this->par = NULL;
    }

    Node(int data) {
        this->data = data;
        this->par = NULL;
    }

    ~Node(){
    }

    void insertChild(Node* chi){
        this -> chi.push_back(chi);
        return;
    }

    void delChild(Node* chi) {
        for(int i = 0; i < this -> chi.size(); i++) {
            if(this->chi[i] == chi) {
                this -> chi.erase(this->chi.begin() + i);
                break;
            }
        }
        return;
    }
};

class GeneralTree{
private:
    Node* root;
    std::vector<Node*> node_list;
public:
    GeneralTree() {
        root = NULL;
    } 
    GeneralTree(int data) {
        root = new Node(data);
        node_list.push_back(root);
    }
    ~GeneralTree(){}
    void setRoot(int data) {
        root = new Node(data);
        node_list.push_back(root);
    }
    Node* getRoot() {
        return root;
    }
    void insertNode(int parent_data, int data) {
        if(root == NULL) {
            setRoot(data);
        }
        else{
            if(findNode(parent_data) == NULL){
                cout << -1 <<"\n";
                return;
            }
            Node* newnode = new Node(data);
            node_list.push_back(newnode);
            newnode->par = findNode(parent_data);
            findNode(parent_data)->chi.push_back(newnode);
        }
    }
    void delNode(int data){
        Node* trashnode = findNode(data);
        if(trashnode != NULL) {
            for(int i{0}; i < trashnode->chi.size(); i++) {
                delNode(trashnode->chi[i]->data);
            }
            for(int i{0}; i < node_list.size(); i++) {
                if(node_list[i] == trashnode) {
                    node_list.erase(node_list.begin() + i);
                }
            }
            delete(trashnode);
        }
    }
    Node* findNode(int data) {
        for(Node* i: node_list) {
            if(i->data == data) {
                return i;
            }
        }
        return NULL;
    }
    void printChild(int data) {
        Node* curnode = findNode(data);
        if(curnode == NULL) cout << -1 << "\n";
        else if(curnode->chi.size() == 0) cout << 0 << "\n";
        else {
            for(Node* i : curnode->chi) {
                cout << i->data << " ";
            }
            cout << "\n";
        }
    }
    int countdepth(int data) {

        Node* curnode = findNode(data);
        if(curnode == NULL) return -1;
        int ans = 0;
        while(!(curnode == root)) {
            ans++;
            curnode = curnode->par;
        }
        return ans;
    }
    void preorder(Node* node) {
        cout << node->data << " ";
        for(Node* i : node->chi) {
            preorder(i);
        }
    }
    void postorder(Node* node) {
        for(Node* i : node-> chi) {
            postorder(i);
        }
        cout << node->data << " ";
    }

};
