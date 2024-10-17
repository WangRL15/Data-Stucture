#include <iostream>
#include <vector>
using namespace std;
vector<int> ans;
vector<vector<int>> graph(51);
vector<int> id(51, 0);
vector<int> lowlink(51, 0);
vector<bool> vis(51, false);
int dfn=0;
int rootJudge = 0;

void dfs(int node,int parent){   
    if(dfn == 0 && graph[node].size() > 1){
        ans.push_back(node);
    }
    id[node] = lowlink[node] = dfn++;
    vis[node]=true;
    for(int &x:graph[node]){
        if(parent == x) continue;
        if(vis[x] == false){
            if(node == 0) rootJudge++;
            dfs(x,node);
            lowlink[node] = min(lowlink[node],lowlink[x]);
            if(id[node] <= lowlink[x])
                ans.push_back(node);
        }
        else 
            lowlink[node] = min(lowlink[node],id[x]);
    }
}
int main(){
    int input1, input2;
    //while(cin >> input1){
    for(int i = 0; i < 6; i++){
        cin >> input1;
        cin >> input2;
        graph[input1].push_back(input2);
        graph[input2].push_back(input1);
    }
    for(int i = 0; i < 50; i++){
        if(!graph[i].empty()){
            if(!vis[i]){
                dfs(i, i);
            }
        }
    } 
    sort(ans.begin(), ans.end());
    auto last = unique(ans.begin(), ans.end());
    ans.erase(last, ans.end());
    if(rootJudge < 2){
        ans.erase(ans.begin());
    }
    if(ans.empty()) cout << "true";
    else{
        cout << "false" << endl;
        bool judge = true;
        for(int i = 0; i < ans.size(); i++) {
            if(judge){
                cout << ans[i];
                judge = false;
            }
            else cout << " " << ans[i];
        }
    }
    return 0;
}
