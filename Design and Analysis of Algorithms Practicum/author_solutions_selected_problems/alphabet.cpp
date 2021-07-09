#include <bits/stdc++.h>

using namespace std;

int n = 256; // number of vertices
vector<int> adj[256]; // adjacency list of graph
vector<bool> visited;
vector<int> ans;
bool isValidSymbol[256];

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (isValidSymbol[i] and !visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

int main(){
    int k;
    cin >> k;

    vector<string> dict;

    for(int i = 0; i < k; i++){
        string s;
        cin >> s;
        dict.push_back(s);
    }

    for(int i = 0; i < dict.size() - 1; i++){
        for(int j = 0; j < min(dict[i].length(), dict[i + 1].length()); j++){
            isValidSymbol[dict[i][j]] = 1;
            isValidSymbol[dict[i + 1][j]] = 1;
            if(dict[i][j] != dict[i + 1][j]){
                adj[dict[i][j]].push_back(dict[i + 1][j]);
                break;
            }
        }
    }

    topological_sort();

    for(auto el : ans){
        cout << (char)el <<  " ";
    }
}
