class Solution {
    void dfs_traversal(vector<vector<int>> &stones, int curr_stone, vector<bool> &vis){
        // marking the current stone as visited
        vis[curr_stone] = true;

        // iterating over the neighbors
        for (int nbr = 0; nbr < stones.size(); nbr ++){
            if (!vis[nbr] && nbr != curr_stone && (stones[nbr][0] == stones[curr_stone][0] || stones[nbr][1] == stones[curr_stone][1])){
                dfs_traversal(stones, nbr, vis);
            }
        }
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        int comp_cnt = 0;
        vector<bool> vis(n, false);
        // counting the number of disconnected components
        for (int i = 0; i < n; i ++){
            if (!vis[i]){
                dfs_traversal(stones, i, vis);
                comp_cnt ++;
            }
        }

        return n - comp_cnt;
    }
};