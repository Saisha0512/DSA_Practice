// DFS Approach : 
class Solution {
    bool dfs(vector<vector<int>> &graph, vector<int> &vis, int node){
        // Visiting the current node : 
        vis[node] = 1;

        // Checking the neighbours : 
        for (int nbr : graph[node]){
            if(vis[nbr] == 1){
                return false; // Cycle Detected
            }
            if (vis[nbr] == 0){
                bool subprob = dfs(graph, vis, nbr);
                if (subprob == false){
                    return false; // Cycle Detected
                }
            }
        }

        // Visited the node : 
        vis[node] = 2;
        return true;
    }

public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < pre.size(); i ++){
            int a = pre[i][0], b = pre[i][1];
            graph[b].push_back(a);
        }

        vector<int> vis(n, 0);
        for (int i = 0; i < n; i ++){
            if(vis[i] == 0){
                if (dfs(graph, vis, i) == false){
                    return false; // Cycle detected
                }
            }
        }

        return true;
    }
};