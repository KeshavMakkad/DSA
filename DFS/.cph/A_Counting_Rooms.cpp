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
int n, m;

void dfs(int x, int y, vvb& visited, vvc& arr){
    visited[x][y] = true;
    for(int i = 0; i < dx.size(); i++){
        int nextI = x + dx[i];
        int nextJ = y + dy[i];
        
        if(0 <= nextI && nextI < n && 0 <= nextJ && nextJ < m){
            if(!visited[nextI][nextJ] && arr[nextI][nextJ] == '.'){
                dfs(nextI, nextJ, visited, arr);
            }
        }
    }
}

int32_t main() {
    cin >> n >> m;
    vvc arr(n, vc(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int count = 0;
    vvb visited(n, vb(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(!visited[i][j] && arr[i][j] == '.'){
                count++;
                dfs(i, j, visited, arr);
            }
        }
    }
    cout << count << endl;
}
