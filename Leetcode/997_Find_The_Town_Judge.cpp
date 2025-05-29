class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n+1, 0), out(n+1, 0);
        for(int i = 0; i < trust.size(); i++){
            int u = trust[i][0];
            int v = trust[i][1];

            in[v]++;
            out[u]++;
        }
        int ans = -1;

        for(int i = 1; i <= n; i++){
            if(out[i] == 0 && in[i] == n-1){
                if(ans != -1){
                    return -1;
                }
                ans = i;
            }
        }
        return ans;
    }
};
