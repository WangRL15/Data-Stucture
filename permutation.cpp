# include <iostream>
# include <vector>
#define SWAP(x, y, t) ((t) = x, (x) = (y), (y) = (t))

using namespace std;

void permutation(string p, int len, int i){
    char temp;
    if(i == len - 1){
        for(int j = 0; j < len; j++) cout << p[j];
        cout << endl;
    }
    else{
        for(int j = i; j < len; j++){
            SWAP(p[i], p[j], temp);
            permutation(p, len, i + 1);
            SWAP(p[i], p[j], temp);
        }
    }
}


int main(){
    int n;
    string p;
    cin >> n;
    cin >> p;
    permutation(p, n, 0);
    
}