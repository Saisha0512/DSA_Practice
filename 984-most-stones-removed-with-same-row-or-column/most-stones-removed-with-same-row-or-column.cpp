class Solution {
    // DFS Function to get the number of connected components : 
    void dfs(vector<vector<int>> &stones, vector<bool> &vis, int curr, int n){
        // Visiting the current stone : 
        vis[curr] = true;

        // Visiting the neighbours of the current stone : 
        for (int nbr = 0; nbr < n; nbr ++){
            // If this stone shares x or y coordinate with the current stone & it is yet to be visited, then we implement dfs on it : 
            if (!vis[nbr] && (stones[curr][0] == stones[nbr][0] || stones[curr][1] == stones[nbr][1])){
                dfs(stones, vis, nbr, n);
            }
        }
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> vis(n, false);
        int cnt = 0;
        // Iterating all the stones & performing dfs on each to count the number of connected components :
        for (int i = 0; i < n; i ++){
            if (!vis[i]){
                cnt ++;
                dfs(stones, vis, i, n);
            }
        }

        return n - cnt;
    }
};