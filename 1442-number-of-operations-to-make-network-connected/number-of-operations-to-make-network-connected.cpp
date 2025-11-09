class Solution {
    void dfs(int node, vector<vector<int>> &graph, vector<bool> &vis){
        vis[node] = true;

        // Visiting the neighbours : 
        for (auto nbr : graph[node]){
            if (!vis[nbr]){
                dfs(nbr, graph, vis);
            }
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // If we have less no of cables : 
        if (connections.size() < n - 1){
            return -1;
        }

        // Adjacency List : 
        vector<vector<int>> graph(n);
        for (auto &conn : connections){
            int a = conn[0], b = conn[1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        // Counting the number of components :
        int comp = 0;
        vector<bool> vis(n, false); // Visiting Vector : 
        for (int i = 0; i < n; i ++){
            if (!vis[i]){
                dfs(i, graph, vis);
                comp ++;
            }
        }

        return comp - 1;
    }
};