class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n+1);
        for(int i =0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n+1, false);

        auto bfs = [&]() -> void {
            queue<int> q;

            q.push(source);
            visited[source] = true;

            while(!q.empty()){
                int curr = q.front();
                q.pop();

                for(auto nb: adj[curr]){
                    if(!visited[nb]){
                        visited[nb] = true;
                        q.push(nb);
                    }
                }
            }
        };

        bfs();

        return visited[destination];
    }
};