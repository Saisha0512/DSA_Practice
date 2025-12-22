class Solution {
    void dfs(vector<vector<int>> &graph, int node, vector<bool> &vis, vector<vector<int>> &res, vector<int> curr){
        // Checking if the current node is the destination node : 
        if (node == graph.size() - 1){
            curr.push_back(node);
            res.push_back(curr);
            return;
        }

        // Otherwise, Visiting the current node : 
        vis[node] = true;
        curr.push_back(node);
        // Iterating over all the unvisited neighbour :
        for (auto nbr : graph[node]){
            if (!vis[nbr]){
                dfs(graph, nbr, vis, res, curr);
            }
        }

        // Backtracking & removing the node from the current path : 
        vis[node] = false;
        curr.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> res;
        vector<int> curr;
        vector<bool> vis(n, false);
        dfs(graph, 0, vis, res, curr);

        return res;
    }
};