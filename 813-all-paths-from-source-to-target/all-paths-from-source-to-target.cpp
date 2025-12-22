class Solution {
    void dfs(vector<vector<int>> &graph, int node, vector<vector<int>> &res, vector<int> curr){
        curr.push_back(node);

        // Checking if the current node is the destination node : 
        if (node == graph.size() - 1){
            res.push_back(curr);
            return;
        }
        // Otherwise, Visiting the current node : 
        else {
            // Iterating over all the unvisited neighbour :
            for (auto nbr : graph[node]){
                dfs(graph, nbr, res, curr);
            }
        }
        
        // Backtracking & removing the node from the current path : 
        curr.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> res;
        vector<int> curr;
        dfs(graph, 0, res, curr);

        return res;
    }
};