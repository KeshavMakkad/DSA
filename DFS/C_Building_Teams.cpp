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

bool dfs(int node, vb& visited, vi& teams){
    if(teams[node] == 0){
        teams[node] = 1;
    }

    visited[node] = true;

    int currTeam = teams[node];
    vi arr = adj[node];

    for(int i = 0; i < arr.size(); i++){
        int curr = arr[i];
        if(teams[curr] == currTeam) return false;
        if(!teams[curr]) teams[curr] = (currTeam == 2) ? 1 : 2;

        if(!visited[curr]){
            bool ans = dfs(curr, visited, teams);
            if(ans == false) return false;
        }
    }
    return true;
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
        int u = edges[i][0]-1;
        int v = edges[i][1]-1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi teams(n, 0);
    vb visited(n, false);

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            bool ans = dfs(i, visited, teams);
            if(!ans){
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
            
        }
    }

    for(int i = 0; i < teams.size(); i++){
        cout << teams[i] << " ";
    }
}