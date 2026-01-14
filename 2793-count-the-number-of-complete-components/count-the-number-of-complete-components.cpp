class Solution {
    void dfs(vector<vector<int>> &graph, vector<bool> &vis, int node, int &nodes, int &edges){
        // Visting the current node : 
        vis[node] = true;
        nodes ++;
        edges += graph[node].size();

        // Iterating over all the neighbors : 
        for (auto nbr : graph[node]){
            // If the nbr is unvisited : 
            if (!vis[nbr]){
                dfs(graph, vis, nbr, nodes, edges);
            }
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Constructing the graph : 
        vector<vector<int>> graph(n);
        for (auto &e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int cnt = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i ++){
            if (!vis[i]){
                int nodes = 0, edges = 0;
                dfs(graph, vis, i, nodes, edges);

                edges /= 2;
                if (edges == nodes * (nodes - 1)/2){
                    cnt ++;
                }
            }
        }

        return cnt;
    }
};