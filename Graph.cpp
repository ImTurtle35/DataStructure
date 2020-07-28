#include <string>
#include <iostream>

using namespace std;
#define MappingSize 501
class vertex{
public:
    vertex *prev;
    vertex *next;
    int degree;
    int data;
    vertex(int data) {
        this->next = NULL;
        this->prev = NULL;
        this->degree = 0;
        this->data = data;
    }
    void increase_degree() {
        this->degree++;
    }
    void decrease_degree() {
        this->degree--;
    }
};

class edge{
public:
    edge* prev;
    edge* next;
    vertex* source;
    vertex* destination;
    string data;
    edge(vertex* a, vertex* b, string data) {
        this->next= NULL;
        this->prev = NULL;
        this->source = a;
        this->destination = b;
        this->data = data;
    }
};

class DoublyVertexLinkedList {
public:
    vertex* head;
    vertex* tail;
    DoublyVertexLinkedList() {
        this->head = NULL;
        this->tail = NULL;
    }
    void insert(vertex* insertVertex) {
        if(this->head == NULL) {
            head = insertVertex;
            tail = insertVertex;
        }
        else {
            tail->next = insertVertex;
            insertVertex->prev = tail;
            tail = insertVertex;
        }
    }
    void remove(vertex* delVertex) {
        if(delVertex == head || delVertex == tail) {
            if(delVertex == head && delVertex != tail) {
                vertex* temp = head;
                head = head->next;
                head->prev = NULL;
                temp = NULL;
                delete temp;
            }
            else if (delVertex == tail && delVertex != head) {
                vertex* temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                temp = NULL;
                delete temp;
            }
            else {
                head = tail = NULL;
            }
        }
        else {
            delVertex->prev->next = delVertex->next;
            delVertex->next->prev = delVertex->prev;
            delVertex = NULL;
            delete delVertex;
        }
    }
};

class DoublyEdgeLinkedList{
public:
    edge* head;
    edge* tail;
    DoublyEdgeLinkedList(){
        this->head= NULL;
        this->tail = NULL;
    }
    void insert(edge* insertEdge){
        if(this->head == NULL){
            head = insertEdge;
            tail = insertEdge;
        }
        else {
            tail->next = insertEdge;
            insertEdge->prev = tail;
            tail = insertEdge;
        }
    }
    void remove(edge* delEdge) {
        if(delEdge == head || delEdge == tail) {
            if(delEdge == head && delEdge != tail) {
                edge* temp = head;
                head = head->next;
                head->prev = NULL;
                temp = NULL;
                delete temp;
            }
            else if (delEdge == tail && delEdge != head) {
                edge* temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                temp = NULL;
                delete temp;
            }
            else {
                head = tail = NULL;
            }
        }
        else {
            delEdge->prev->next = delEdge->next;
            delEdge->next->prev = delEdge->prev;
            delEdge=NULL;
            delete delEdge;
        }
    }
};

class graph{
public:
    edge*** edgeMatrix;
    DoublyVertexLinkedList* VertexList;
    DoublyEdgeLinkedList* EdgeList;
    int vertexSize;
    int edgeSize;
    int mappingTable[MappingSize];

    graph() {
        this->VertexList = new DoublyVertexLinkedList();
        this->EdgeList = new DoublyEdgeLinkedList();
        this->vertexSize = 0;
        this->edgeSize = 0;
        for(int i = 0; i < MappingSize; i++)mappingTable[i] = -1;
        this->edgeMatrix = new edge** [1];
        this->edgeMatrix[0] = new edge*[1];
        this->edgeMatrix[0][0] = NULL;
    }

    bool isfindVertex(int n) {
        bool flag = false;
        vertex* temp = VertexList->head;
        while(temp != NULL) {
            if(temp->data == n) {
                flag = true;
                break;
            }
            temp = temp->next;
        }
        return flag;
    }

    vertex* findVertex(int n) {
        vertex* temp = VertexList->head;
        while(temp != NULL){
            if(temp->data == n) {
                break;
            }
            temp = temp->next;
        }
        return temp;
    }

    void insert_vertex(int n) {
        if(isfindVertex(n) == true){
            return;
        }
        else {
            edge*** tempMatrix = new edge**[vertexSize + 1];
            for(int i = 0; i < vertexSize + 1; i++) {
                tempMatrix[i] = new edge*[vertexSize+1];
                for (int j =0 ; j < vertexSize + 1; j++) {
                    tempMatrix[i][j] = NULL;
                }
            }
            for(int i= 0; i < vertexSize; i++) {
                for(int j = 0; j < vertexSize; j++) {
                    tempMatrix[i][j] = this->edgeMatrix[i][j];
                }
            }
            this->edgeMatrix = tempMatrix;
            vertex* newVertex = new vertex(n);
            VertexList->insert(newVertex);
            this->vertexSize++;
            mappingTable[vertexSize-1]=n;
        }
    }

    void erase_vertex(int n) {
        if(isfindVertex(n) == false || vertexSize == 0) {
            return;
        }
        else {
            edge*** tempMatrix = new edge**[vertexSize - 1];
            for (int i = 0; i < vertexSize - 1; i++) {
                tempMatrix[i] = new edge*[vertexSize-1];
                for(int j=0; j<vertexSize-1; j++) {
                    tempMatrix[i][j] = NULL;
                }
            }
            int middleidx = 0;
            for(int i = 0; i < vertexSize; i++) {
                if(mappingTable[i] == n) middleidx = 1;
            }
            for(int i = middleidx; i < vertexSize; i++) {
                mappingTable[i] = mappingTable[i+1];
            }
            for(int i = 0; i < vertexSize; i++) {
                if(this->edgeMatrix[middleidx][i] != NULL) {
                    EdgeList->remove(this->edgeMatrix[middleidx][i]);
                }
            }
            for(int i= 0; i < vertexSize; i++) {
                for(int j = 0; j < vertexSize; j++) {
                    if(i < middleidx && j<middleidx) {
                        tempMatrix[i][j] = this->edgeMatrix[i][j];
                    }
                    else if (i > middleidx && j > middleidx) {
                        tempMatrix[i-1][j-1] = this->edgeMatrix[i][j];
                    }
                    else if (j > middleidx) {
                        tempMatrix[i][j-1] = this->edgeMatrix[i][j];
                    }
                    else if (i > middleidx) {
                        tempMatrix[i-1][j] = this->edgeMatrix[i][j];
                    }
                }
            }
            this->edgeMatrix=tempMatrix;
            VertexList->remove(findVertex(n));
            this->vertexSize--;
        }
    }

    void insert_edge(int indirectSource, int indirectDestination, string data) {
        if(isfindVertex(indirectSource) == false || isfindVertex(indirectDestination) == false) {
            cout << -1 << endl;
            return;
        }
        int destination = -1;
        int source = -1;
        for (int i = 0; i <= vertexSize; i ++) {
            if(mappingTable[i] == indirectDestination)destination = i;
            if(mappingTable[i] == indirectSource) source = i;
            if(source != -1 && destination != -1) break;
        }
        if(edgeMatrix[source][destination] != NULL || edgeMatrix[destination][source] !=NULL){
            cout << -1 << endl;
            return;
        }
        edge* newEdge = new edge(findVertex(indirectSource), findVertex(indirectDestination), data);
        edgeMatrix[source][destination] = newEdge;
        edgeMatrix[destination][source] = newEdge;
        findVertex(indirectSource)->increase_degree();
        findVertex(indirectDestination)->increase_degree();
        EdgeList->insert(newEdge);
        this->edgeSize++;
    }

    void erase_edge(int indirectSource, int indirectDestination) {
        int destination = -1;
        int source = -1;
        for (int i = 0; i <= vertexSize; i++) {
            if(mappingTable[i] == indirectDestination)destination = i;
            if(mappingTable[i] == indirectSource)source =i;
            if(source != -1 && destination != -1) break;
        }
        if(edgeMatrix[source][destination] == NULL || edgeMatrix[destination][source] == NULL) {
            return;
        }
        findVertex(indirectSource)->decrease_degree();
        findVertex(indirectDestination)->decrease_degree();
        edge* delEdge = edgeMatrix[source][destination];
        EdgeList->remove(delEdge);
        edgeMatrix[source][destination] = NULL;
        edgeMatrix[destination][source] = NULL;
        this->edgeSize--;
    }

    void isFindEdge(int indirectSource, int indirectDestination) {
        if(isfindVertex(indirectSource) == false || isfindVertex(indirectDestination) == false) {
            cout << -1 << endl;
            return;
        }
        int destination = -1;
        int source = -1;
        for (int i = 0; i <= vertexSize; i ++) {
            if(mappingTable[i] == indirectDestination)destination = i;
            if(mappingTable[i] == indirectSource) source = i;
            if(source != -1 && destination != -1) break;
        }
        if(edgeMatrix[source][destination] != NULL || edgeMatrix[destination][source] !=NULL){
            cout << 1 << endl;
            return;
        }
        else 
        cout << 0 << endl;
        return;
    }
};

int main() {
    int N, M, K, input, s, d;
    cin >> N>> M;
    graph G;
    for(int i{0}; i< N; i++) {
        cin >> input;
        G.insert_vertex(input);
    }
    for(int i{0}; i<  M; i++) {
        cin >> s >> d;
        G.insert_edge(s,d, "");
    }
    cout << G.vertexSize << " " << G.edgeSize << "\n";
    /*for(int i{0}; i < K; i++) {
        cin >> s >> d;
        G.isFindEdge(s,d);
    }*/

}