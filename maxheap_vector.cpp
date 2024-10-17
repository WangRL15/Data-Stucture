# include <iostream>
# include <vector>

using namespace std;
struct element{
    string todo;
    int p;
};

vector<element> max_heap;

void insert(element item){
    int i = max_heap.size();
    max_heap.push_back(item);
    while(i != 0 && max_heap[(i-1) / 2].p < item.p ){
        max_heap[i] = max_heap[(i-1) / 2];
        i = (i-1) / 2;
    }
    max_heap[i] = item;
}

element pop_element(){
    element item = max_heap[0];
    int n = max_heap.size()-1;
    int child = 0, parent = 0;
    while((2 * child) + 1 < n){
        child = 2*child + 1;
        if((child + 1) < n && max_heap[child].p < max_heap[child + 1].p) child++;
        if(max_heap[n].p < max_heap[child].p){
            max_heap[parent] = max_heap[child];
            parent = child;
        }
    }
    max_heap[parent] = max_heap[n];
    max_heap.pop_back();

    return item;
}

int main(){
    int m;
    int key;
    string thing;
    cin >> m;

    for(int i = 0; i < m; i++){
        cin >> thing >> key;
        element item;
        item.p = key;
        item.todo = thing;
        insert(item);
    }

    cout << "First three things to do:\n";
    element a = pop_element();
    cout << a.todo << endl;
    a = pop_element();
    cout << a.todo << endl;
    a = pop_element();
    cout << a.todo << endl;
}