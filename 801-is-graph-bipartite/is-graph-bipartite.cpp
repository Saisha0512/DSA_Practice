class Solution {
    bool graphColoring(vector<vector<int>> &graph, vector<int> &vis, int color, int node, int parent){
        // Coloring the current node reached : 
        vis[node] = color;

        // Coloring the neighbors : 
        for (auto nbr : graph[node]){
            // If the neighbor is unvisited : 
            if (!vis[nbr]){
                bool subprob = graphColoring(graph, vis, 3 - color, nbr, node);
                if (subprob == false){
                    return false;
                }
            }
            // If an already visited neigbor has the same color as the current node : 
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
            if (!vis[i]){
                bool subprob = graphColoring(graph, vis, 1, i, -1);

                if (subprob == false){
                    return false;
                }
            }
        }

        return true;
    }
};