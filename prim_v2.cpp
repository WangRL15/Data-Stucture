# include<iostream>
# include<vector>
# include<utility>
# define MAX_WEIGHT 10000
using namespace std;

vector<vector<int> >g;
int num;

void addEdge(int a, int b, int weight){
    g[a][b] = weight;
    g[b][a] = weight;
}

bool compareEdge(pair<int , int> a, pair<int, int> b){
    if(a.first == b.second) return a.second < b.second;
    return a.first < b.first;
}

void MST(){
    int p[num], key[num];
    bool vis[num];
    for(int i = 0; i < num; i++){
        p[i] = -1;
        vis[i] = false;
        key[i] = MAX_WEIGHT;
    }
    key[0] = 0;
    for(int i = 0; i < num; i++){
        int x = MAX_WEIGHT, u;
        for(int j = 0; j < num ; j++){
            if(!vis[j] && key[j] < x){
                x = key[j];
                u = j;
            }
        }
        vis[u] = true;
        for(int j = 0; j < num; j++){
            if(!vis[j] && g[u][j] != 0 && (g[u][j] < key[j])){
                p[j] = u;
                key[j] = g[u][j];
            }
        }
    }
    int total_weight = 0;
    vector<pair<int, int> > ans;
    for(int i = 0; i < num ; i++){
        if(p[i] == -1) continue;
        if(i > p[i]) ans.push_back(make_pair(p[i], i));
        else ans.push_back(make_pair(i, p[i]));
        total_weight += key[i];
    }

    sort(ans.begin(), ans.end(), compareEdge);
    cout << total_weight << endl;
    for(int i = 0; i < num - 1; i++){
        printf("city%d - city%d", ans[i].first+1, ans[i].second+1);
        if(i != num - 2) cout << endl;
    }
}


int main(){
    int e, a, b, weight;
    cin >> num >> e;
    g.resize(num);
    for(int i = 0; i < num; i++)
        g[i].resize(num);
    for(int i = 0; i < e; i++){
        cin >> a >> b >> weight;
        addEdge(a-1, b-1, weight);
    }
    MST();
    return 0;
}