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

int dfs(int node, vb& visited){
    int count = 1;
    visited[node] = true;

    vi arr = adj[node];
    for(int i = 0; i < arr.size(); i++){
        int curr = arr[i];
        if(!visited[curr]){
            count += dfs(curr, visited);
        }
    }
    return count;
}

int32_t main(){
    int n, m; cin >> n >> m;
    vvi edges(m, vi(2));

    for(int i = 0; i < m; i++){
        cin >> edges[i][0] >> edges[i][1];
    }

    adj.clear();
    adj.resize(n);

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vb visited(n, false);

    int ans = 0;
    int prev = 0;

    for(int i = 0; i< n; i++){
        if(!visited[i]){
            int len = dfs(i, visited);
            ans = ans + prev * len;
            prev += len;
        }
    }
    cout << ans << endl;
}