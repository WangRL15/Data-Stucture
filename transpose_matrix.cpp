#include <iostream>
#include <vector>
typedef struct{
    int col;
    int row;
    int val;
} term;

using namespace std;

void transpose(term a[101], term b[101]){
    vector<int> starting_pos(a[0].col, 0);
    vector<int> count(a[0].col, 0);
    b[0].col = a[0].row;
    b[0].row = a[0].col;
    b[0].val = a[0].val;
    for(int i = 1; i <= a[0].val; i++){
        count[a[i].col]++;
    }
    starting_pos[0] = 1;
    for(int i = 1; i < a[0].col; i++){
        starting_pos[i] = starting_pos[i-1] + count[i-1];
    }
    for(int i = 1; i <= a[0].val; i++){
        b[starting_pos[a[i].col]].row = a[i].col;
        b[starting_pos[a[i].col]].col = a[i].row;
        b[starting_pos[a[i].col]].val = a[i].val;
        starting_pos[a[i].col]++;
    }    
}


int main(){
    term a[101], b[101];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].row >> a[i].col >> a[i].val;
    }
    transpose(a, b);
    for(int i = 0; i < n; i++){
        cout << b[i].row << " " << b[i].col << " " << b[i].val << endl;
    }
}