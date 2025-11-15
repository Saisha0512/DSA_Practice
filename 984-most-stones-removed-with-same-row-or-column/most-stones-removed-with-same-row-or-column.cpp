class Solution {
    int dfs(vector<vector<int>> &stones, vector<bool> &vis, int i, int n){
        // Visiting the current stone : 
        vis[i] = true;

        // Getting the result after removing this stones neighbours : 
        int res = 0;
        for (int j = 0; j < n; j ++){
            if (!vis[j] && (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])){
                res += 1 + dfs(stones, vis, j, n);
            }
        }

        return res;
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> vis(n, false);
        int cnt = 0;
        // Iterating all the stones & performing dfs on each to remove its neighbours :
        for (int i = 0; i < n; i ++){
            if (!vis[i]){
                cnt += dfs(stones, vis, i, n);
            }
        }

        return cnt;
    }
};