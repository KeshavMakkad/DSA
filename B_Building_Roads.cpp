#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define vvi vector<vi>
#define vvb vector<vb>
#define vvc vector<vc>
#define vpi vector<pair<int, int>>
#define pi pair<int, int>

vvi adj;

void makeAdjList(vvi& edges) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0]-1;
        int v = edges[i][1]-1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int node, vb& visited){
    visited[node] = true;
    vi arr = adj[node];
    for(int i = 0; i < arr.size(); i++){
        if(!visited[arr[i]]){
            dfs(arr[i], visited);
        }
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    vvi edges(m, vi(2));

    adj.clear();
    adj.resize(n);

    vb visited(n, false);

    for(int i = 0; i < m; i++){
        cin >> edges[i][0] >> edges[i][1];
    }
    makeAdjList(edges);

    vvi ans;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            ans.push_back({1, i+1});
            dfs(i, visited);
        }
    }

    cout << ans.size()-1 << endl;
    for(int i = 1; i < ans.size(); i++){
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
}