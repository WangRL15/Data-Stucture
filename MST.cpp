# include <iostream>
# include <vector>
# include <utility>
# define MAX_WEIGHT 10000
using namespace std;

int n;
vector<vector<int> > g;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

void addEdge(int a, int b, int w){
    g[a][b] = g[b][a] = w;
}

void mst(){
    int p[n], key[n];
    bool vis[n];
    for(int i = 0; i < n; i++){
        p[i] = -1;
        key[i] = MAX_WEIGHT;
        vis[n] = false;
    }

    key[0] = 0;
    for(int i = 0; i < n; i++){
        int w = MAX_WEIGHT;
        int u;
        for(int j = 0; j < n; j++){
            if(key[i] < w){
                u = i;
                w = key[i];
            }
        }
        vis[u] = true;
        for(int j = 0; j < n; j++){
            if(!vis[j] && g[u][j] != 0 && g[u][j] < key[j]){
                key[j] = g[u][j];
                p[j] = u;
            }
        }
    }

    // print
    vector<pair<int, int> > ans;
    int total_weight = 0;

    for(int i = 1; i < n; i++){
        total_weight += key[i];
        if(p[i] > i) ans.push_back(make_pair(i, p[i]));
        else ans.push_back(make_pair(p[i], i));
    }
    sort(ans.begin(), ans.end(), cmp);
    cout << total_weight << endl;
    for(int i = 1; i < n; i++){
        printf("city%d - city%d", ans[i].first+1, ans[i].second+1);
        if(i < n-1) cout << endl;
    }

}

int main(){
    int e, a, b, w;
    cin >> n >> e;
    g.resize(n);
    for(int i = 0; i < n; i++){
        g[i].resize(n);
    }
    for(int i = 0; i < e; i++){
        cin >> a >> b >> w;
        addEdge(a-1, b-1, w);
    }
    mst();
    return 0;
}