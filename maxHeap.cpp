#include<iostream>
using namespace std;
#define MAX_ELEMENT 1000000
typedef struct{
    int key;
    string thing;
} element;
element heap[MAX_ELEMENT];
int n;

void insert(element item){
    int i;
    i = ++n;
    while( (i != 0) && (item.key > heap[i/2].key)){
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = item;
}


element compareNode(element item1, element item2){
    if(item1.key > item2.key) return item1;
    return item2;
}

element maxChild(int n){
    return compareNode(heap[2*n + 1], heap[2*n+2]);
}

int main(){
    int m;
    int key;
    string thing;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> thing >> key;
        element item;
        item.key = key;
        item.thing = thing;
        insert(item);
    }
    cout << "First three things to do:\n" << heap[0].thing << '\n';

    // find the second one;
    int parent, child;
    if(heap[1].key > heap[2].key) {
        cout << heap[1].thing << '\n';
        cout << compareNode(heap[2], maxChild(1)).thing << '\n';
    }

    else{
        cout << heap[2].thing << '\n';
        cout << compareNode(heap[1], maxChild(2)).thing << '\n';
    }


    return 0;
}