#include<iostream>
#include<vector>
#include<stack>
#include<utility>
using namespace std;


const int MAX_INT = 100;
int m, n;
int maze[MAX_INT][MAX_INT];
stack<pair<int, int> > path;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool isValid(int x, int y){
    if(x >= 0 && y >= 0 && x < m && y < n) return maze[x][y] == 0;
    return false;
}

bool dfs(int x, int y){
    if(x == m-1 && y == n-1){
        path.push(make_pair(x, y));
        return true;
    }
    if(isValid(x, y)){
        maze[x][y] = 1;
        for(int i = 0; i < 4; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(dfs(newX, newY)){
                path.push(make_pair(x, y));
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        for(int j = 0;j < n; j++) cin >> maze[i][j];
    }
    if(dfs(0, 0)){
        while(!path.empty()){
            pair<int, int> point = path.top();
            cout << "(" << point.first << "," << point.second << ")";
            path.pop();
            if(!path.empty()) cout << " ";
        }
    }
    else{
        cout << "Can't reach the exist";
    }
}