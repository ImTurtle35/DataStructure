#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* par;
    vector<Node*>chi;

    Node();
    Node(int e);
};

int main() {
    
}