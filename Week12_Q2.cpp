#include <iostream>

#define MAX 353333
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

using namespace std;

class item{
public:
    int key,value;
};

class arr{
public:
    item* data;
    int flag = NOITEM;
};
arr HashArr[MAX];
int sz = 0;

int hashfunc(int idx) {
    return idx % MAX;
}

int hashfunc2(int idx) {
    return (17-(idx%17));
}

void tableinsertDouble(int key, int value) {
    item* newitem = new item{key,value};
    int idx = hashfunc(key);
    if(HashArr[idx].flag == ISITEM) {
        int j = 1;
        idx = hashfunc(hashfunc(key) + j *hashfunc2(key));
        while(true){
            if(HashArr[idx].flag != ISITEM){
                HashArr[idx].data = newitem;
                HashArr[idx].flag = ISITEM;
                sz++;
                break;
            }
            idx = hashfunc(hashfunc(key) + j *hashfunc2(key));
            j++;
        }
    }
    else {
        HashArr[idx].flag = ISITEM;
        HashArr[idx].data = newitem;
        sz++;
    }
}

void tableSearchDouble(int key, int value) {
    int idx = hashfunc(key);
    int probing = 1;
    while(probing <= MAX && HashArr[idx].flag != NOITEM && HashArr[idx].data != NULL){
        if(HashArr[idx].data->key == key) {
            cout << 1 << " " << probing <<"\n";
            return;
        }
        idx = hashfunc(hashfunc(key) + (probing)*hashfunc2(key));
        probing++;
    }
    cout << 0 << " " << probing << "\n";
}

int main() {
    int T, N, M, input;
    cin >> T;
    while(T--) {
        for(int i{0}; i < MAX; i++) {
            if(HashArr[i].data)
                HashArr[i].data = NULL;
            HashArr[i].flag = NOITEM;
        }
        cin >> N;
        for(int i{0}; i < N; i++) {
            cin >> input;
            tableinsertDouble(input,input);
        }
        cin >> M;
        for(int i{0}; i < M; i++) {
            cin >> input;
            tableSearchDouble(input,input);
        }
    }
}