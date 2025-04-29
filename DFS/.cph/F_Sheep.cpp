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

vi dfs(int x, int y, vvc& arr, vvb& visited){
    int n = arr.size(), m = arr[0].size();
    visited[x][y] = true;
    vi count = {0,  0};
    if(arr[x][y] == 'k') count[0]++;
    else if(arr[x][y] == 'v') count[1]++;

    for(int i = 0; i < dx.size(); i++){
        int nextX = x + dx[i], nextY = y + dy[i];
        if(nextX >= 0 && nextY >= 0 && nextX < n && nextY < m){
            if(!visited[nextX][nextY] && arr[nextX][nextY] != '#'){
                vi ret = dfs(nextX, nextY, arr, visited);
                count[0] += ret[0];
                count[1] += ret[1];
            }
        }
    }

    return count;
}

int32_t main(){
    int n, m; cin >> n >> m;

    vvc arr(n, vc(m));

    for(int i = 0; i< n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    vvb visited(n, vb(m, false));

    int sheep = 0, wolves = 0;

    for(int i = 0; i< n; i++){
        if(!visited[i][0] && arr[i][0] != '#'){
            vi ans = dfs(i, 0, arr, visited);
            sheep += ans[0];
            wolves += ans[1];
        }
        if(!visited[i][m-1] && arr[i][m-1] != '#'){
            vi ans = dfs(i, m-1, arr, visited);
            sheep += ans[0];
            wolves += ans[1];
        }
    }

    for(int i = 0; i< m; i++){
        if(!visited[0][i] && arr[0][i] != '#'){
            vi ans = dfs(0, i, arr, visited);
            sheep += ans[0];
            wolves += ans[1];
        }
        if(!visited[n-1][i] && arr[n-1][i] != '#'){
            vi ans = dfs(n-1, i, arr, visited);
            sheep += ans[0];
            wolves += ans[1];
        }
    }

    for(int i = 1; i < n-1; i++){
        for(int j = 1; j < m-1; j++){
            if(!visited[i][j] && arr[i][j] != '#'){
                vi ans = dfs(i, j, arr, visited);
                if(ans[0] > ans[1]) sheep += ans[0];
                else wolves += ans[1];
            }
        }
    }
    cout << sheep << " " << wolves << endl;
}