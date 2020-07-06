#include <iostream>
#include <string>
#include <cmath>

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
        if(idx < 0 || idx >= n || n == 0)
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

int calcul(int ac, int cc) {
    if (cc == 0) return 0;
    else return ac/cc;
}

int main() {
    int M, N, X;
    string input;
    cin >> M;
    while(M--) {
        cin >> N;
        Array arr(N);
        for(int i{0}; i < N; i++) {
            cin>> X;
            arr.add(i,X);
        }
        int kor = 0, jp = 0, ch = 0;
        int kc = 0, jc = 0, cc = 0;
        for(int i{0}; i < N; i++) {
            if(i % 3 == 0) {
                kor += arr.at(i);
                if(arr.at(i) != 0)
                kc++;
            } else if (i % 3 == 1) {
                jp += arr.at(i);
                if(arr.at(i) != 0)
                jc++;
            } else {
                ch += arr.at(i);
                if(arr.at(i) != 0)
                cc++;
            }
        }
        cout << kor << " " << jp << " " << ch <<"\n";
    }
}