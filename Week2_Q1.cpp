#include <iostream>
#include <string>

using namespace std;

class Array{
public:
    int n;
    int* arr;

    Array(int size){
        this->n=0;
        this->arr=new int[size];
        for(int i= 0; i < size; i++) {
            arr[i]=0;
        }
    }

    int at(int idx) {
        if (idx >= 0 && idx < n) {
            return arr[idx];
        }
        else {
            return 0;
        }
    }

    void set(int idx, int X) {
        if (idx >= 0 && idx < n && n > 0) {
            arr[idx] = X;
        }
        else {
            cout << 0 << "\n";
        }
    }

    void add(int idx, int X) {
        if (idx >= 0 && idx < n && n > 0) {
            int save;
            int save2 = X;
            for(int i{idx}; i <= n; i++) {
                save = arr[i];
                arr[i] = save2;
                save2 = save;
            }
        }
        else {
            arr[n] = X;
        }
        n++;
    }

    int remove(int idx) {
        if((idx < 0 && idx >= n) || n == 0)
           return 0;
        int value = arr[idx];
        for(int i{idx}; i < n; i++) {
            arr[i] = arr[i+1];
        } 
        n--;
        arr[n] = 0;
        return value;
    }

    void printArray() {
        if(n == 0) {
            cout << 0 << "\n";
        }
        else {
            for(int i{0}; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Array arr(10000);
    int M, i, X;
    string input;
    cin >> M;
    while(M--) {
        cin >> input;
        if(input == "at"){
            cin >> i;
            cout << arr.at(i) << "\n";
        } else if (input == "set") {
            cin >> i >> X;
            arr.set(i,X);
        } else if (input == "add") {
            cin >> i >> X;
            arr.add(i,X);
        } else if (input == "remove") {
            cin >> i;
            cout << arr.remove(i) << "\n";
        } else if (input == "printArray"){
            arr.printArray();
        }
    }
}