class Solution {
    bool dfs(vector<vector<int>> &graph, vector<int> &vis, int node){
        // Checking if the current node is terminal node : 
        if (graph[node].size() == 0){
            return true;
        }

        // Visiting the current node : 
        vis[node] = 1;

        // Otherwise checking for all the paths from that node : 
        for (int nbr : graph[node]){
            // If the nbr is in the current path - Cycle Detected : 
            if (vis[nbr] == 1){
                return false;
            }
            // If the nbr is unvisited : 
            if (vis[nbr] == 0){
                bool subprob = dfs(graph, vis, nbr);
                if (subprob == false){
                    return false;
                }
            }
        }

        // Mark the current node visited : 
        vis[node] = 2;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        // Making the set of terminal nodes : 
        set<int> terminal;
        for (int i = 0; i < n; i ++){
            if (graph[i].size() == 0){
                terminal.insert(i);
            }
        }

        // Result Vector : 
        vector<int> res;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i ++){
            bool check = dfs(graph, vis, i);
            if (check == true){
                res.push_back(i);
            }
            vis = vector<int>(n, 0);
        }

        return res;
    }
};