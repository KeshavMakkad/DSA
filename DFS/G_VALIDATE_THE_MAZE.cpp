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

vi dx{1, -1, 0, 0};
vi dy{0, 0, 1, -1};

int dfs(int x, int y, vvc& arr, vvb& visited){
    visited[x][y] = true;

    int count = 0;

    if(x == 0 || y == 0 || x == arr.size()-1 || y == arr[0].size()-1){
        // cout << x << " " << y << " ";
        count += 1;
    }

    for(int i = 0; i< dx.size(); i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < arr.size() && ny < arr[0].size()){
            if(!visited[nx][ny] && arr[nx][ny] == '.'){
                count += dfs(nx, ny, arr, visited);
            }
        }
    }
    return count;
}

int32_t main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;

        vvc maze(n, vc(m));

        vvi openings;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> maze[i][j];
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && maze[i][j] == '.'){
                    openings.push_back({i, j});
                }
            }
        }
        if(openings.size() != 2){
            cout << "invalid" << endl;
            continue;
        }

        vvb visited(n, vb(m, false));

        int val = dfs(openings[0][0], openings[0][1], maze, visited);
        // cout << 6-t << " " << val;

        if(val == 2){
            cout << "valid" << endl;
        } else {
            cout << "invalid" << endl;
        }
        
    }
}