class Solution {
    int timer = 0;
    vector<vector<int>> critical;
    
    void dfs_traversal(vector<vector<int>> &graph, vector<int> &time, vector<int> &low, vector<bool> &vis, int curr_node, int parent){
        // visiting the current node
        vis[curr_node] = true;

        // updating the time of visiting the current node
        time[curr_node] = low[curr_node] = timer;
        timer ++;

        // iterating over all the neighbors
        for (auto &nbr : graph[curr_node]){
            if (nbr == parent)      continue;
            else if (!vis[nbr]){
                dfs_traversal(graph, time, low, vis, nbr, curr_node);

                // after this recursive dfs call returns
                low[curr_node] = min(low[curr_node], low[nbr]);

                // checking if on removing this edge curr_node === nbr
                // will we be able to reach the nbr from curr_node
                if (low[nbr] > time[curr_node]){ 
                    // a critical connections
                    critical.push_back({curr_node, nbr});
                }
            }
            else if (vis[nbr] && nbr != parent){
                low[curr_node] = min(low[curr_node], low[nbr]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // adjacency list
        vector<vector<int>> graph(n);
        for (auto &e : connections){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        vector<int> time(n), low(n);
        dfs_traversal(graph, time, low, vis, 0, -1);

        return critical;
    }
};