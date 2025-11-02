class Solution {
    bool dfs(vector<vector<int>> &graph, int node, vector<int> &vis, int color, int parent){
        // Visiting the current node : 
        vis[node] = color;

        // Visiting the neighbours : 
        for (auto nbr : graph[node]){
            // An unvisited Neighbour : 
            if (vis[nbr] == 0){
                int subprob = dfs(graph, nbr, vis, 3 - color, node);
                if (subprob == false){
                    return false;
                }
            }
            // A visited neighbour with the same color :
            else if (nbr != parent && vis[nbr] == color){
                return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i ++){
            if (vis[i] == 0){
                bool flag = dfs(graph, i, vis, 1, -1);
                if (flag == false){
                    return false;
                }
            }
        }

        return true;
    }
};