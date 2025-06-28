class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int num1 = edges[0][0];
        int num2 = edges[0][1];

        if(edges[1][0] == num1 || edges[1][0] == num2){
            return edges[1][0];
        }
        else return edges[1][1];
    }
};


