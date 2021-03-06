#include <iostream>
#include <vector>
#include <string>

using namespace std;
enum direction { MIN = 1, Max = -1 };

class Heap{
private:
    vector<int>v;
    int heap_size;
    int root_index;
    int direction;
public:
    Heap(int direction) {
        v.push_back(-1);
        this->heap_size = 0;
        this->root_index = 1;
        this->direction = direction;
    }
    void swap(int idx1, int idx2) {
        int save = v[idx1];
        v[idx1] = v[idx2];
        v[idx2] = save;
    }
    void upHeap(int idx) {
        if(idx == root_index) return;
        int par = idx/2;
        if(direction == MIN && v[par] <= v[idx]) return;
        else if (direction == Max && v[par] >= v[idx]) return;
        swap(par,idx);
        upHeap(par);
    }
    void downHeap(int idx){
        int left = 2 * idx; int right = 2 * idx + 1;
        int smaller = left;
        int higher = right;
        if(right <= heap_size) {
            if(v[left] > v[right]){
                smaller = right;
                higher = left;
            }
        }
        else if (left <= heap_size) {
            higher = left;
        }
        else
            return;
        if(direction == MIN && v[smaller] < v[idx]) {
            swap(smaller,idx);
            downHeap(smaller);
        }
        else if (direction == Max && v[higher] > v[idx]){
            swap(higher,idx);
            downHeap(higher);
        }
    }
    void insert(int e){
        v.push_back(e);
        heap_size++;
        upHeap(heap_size);
    }
    int pop() {
        if(isEmpty()){
            return -1;
        }
        int save = v[root_index];
        v[root_index] = v[heap_size];
        heap_size--;
        downHeap(root_index);
        v.pop_back();
        return save;
    }
    int top() {
        if(isEmpty()){
            return -1;
        }
        return v[root_index];
    }
    int size() {
        return heap_size;
    }
    bool isEmpty(){
        return (heap_size == 0);
    }
    void print(){
        if(isEmpty()) {
            cout << -1 << "\n";
            return;
        }
        for(int i{1}; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
    }

    void printAt(int idx){
        cout << v[idx] << "\n";
    }
};

int main() {
    int T,N,p,e;
    cin >> T;
    while(T--){
        Heap minheap(MIN);
        Heap maxheap(Max);
        cin >> N >> p;
        while(N--) {
            cin >> e;
            minheap.insert(e);
            maxheap.insert(e);
        }
        minheap.printAt(p);
        vector<int>minsorted;
        minsorted.push_back(0);
        while(!minheap.isEmpty())
        minsorted.push_back(minheap.pop());
        cout << minsorted[p] << "\n";
        maxheap.printAt(p);
        vector<int>maxsorted;
        maxsorted.push_back(0);
        while(!maxheap.isEmpty())
        maxsorted.push_back(maxheap.pop());
        cout << maxsorted[p] << "\n";
    }
}