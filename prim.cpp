// C++ code
#include <iostream>
#include <vector>
#include <iomanip>      // for setw()
#include <utility>

const int Max_Weight = 1000;    // 初始化key[]時需要infinity, 以Max_Weight代替

bool compareFunction(std::pair<int, int> a, std::pair<int, int> b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

class GraphMST{
private:
    int num_vertex;
    std::vector<std::vector<int> > AdjMatrix;
public:
    GraphMST():num_vertex(0){};
    GraphMST(int n):num_vertex(n){
        AdjMatrix.resize(num_vertex);
        for (int i = 0; i < num_vertex; i++) {
            AdjMatrix[i].resize(num_vertex);
        }
    }
    void AddEdge(int from, int to, int weight);

    void PrimMST(int Start = 0);        // 可以指定起點Start, 若沒有指定, 則從vertex(0)作為MST的root
    friend int MinKeyExtract(int *key, bool *visited, int size);
};

int MinKeyExtract(int *key, bool *visited, int size){

    int min = Max_Weight, min_idx = 0;
    for (int i = 0; i < size; i++) {
        if (visited[i]==false && key[i]<min) {
            min = key[i];
            min_idx = i;
        }
    }
    return min_idx;
}
void GraphMST::PrimMST(int Start){

    int key[num_vertex], predecessor[num_vertex];
    bool visited[num_vertex];

    for (int i = 0; i < num_vertex; i++) {
        key[i] = Max_Weight;
        predecessor[i] = -1;
        visited[i] = false;     // false表示vertex還沒有被visited
    }

    key[Start] = 0;
    for (int i = 0; i < num_vertex; i++) {
        int u = MinKeyExtract(key, visited, num_vertex);
        visited[u] = true;
        for (int i = 0; i < num_vertex; i++) {
            if ( visited[i]==false && AdjMatrix[u][i]!=0 && AdjMatrix[u][i]<key[i]) {
                predecessor[i] = u;
                key[i] = AdjMatrix[u][i];
            }
        }
    }
    // print MST
    std::vector<std::pair<int, int> > ans;
    int total_weight = 0;
    for(int i = 0; i < num_vertex; i++){
        if(predecessor[i] == -1) continue;
        if(i > predecessor[i])
            ans.push_back(std::make_pair(predecessor[i], i));
        else ans.push_back(std::make_pair(i, predecessor[i]));
        total_weight += key[i];
    }

    sort(ans.begin(), ans.end(), compareFunction);

    std::cout << total_weight << std::endl;
    for(int i = 0; i < num_vertex - 1; i++){
        printf("city%d - city%d", ans[i].first+1, ans[i].second+1);
        if(i != num_vertex-1) std::cout << std::endl;
    }
}
void GraphMST::AddEdge(int from, int to, int weight){
    AdjMatrix[from][to] = AdjMatrix[to][from] = weight;
    
}

int main(){
    int n, e, a, b, w;
    std::cin >> n >> e;
    GraphMST g(n);
    for(int i = 0; i < e; i++){
        std::cin >> a >> b >> w;
        g.AddEdge(a-1, b-1, w);
    }
    
    g.PrimMST();

    return 0;
}