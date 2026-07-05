class Solution {
    int curr_time = 1;
    vector<vector<int>> res;

    void dfs_traversal(vector<vector<int>> &graph, vector<bool> &vis, vector<int> &time, vector<int> &low, int curr_node, int parent){
        vis[curr_node] = true;

        low[curr_node] = curr_time;
        time[curr_node] = curr_time;
        curr_time ++;

        for (int nbr : graph[curr_node]){
            if (!vis[nbr]){
                dfs_traversal(graph, vis, time, low, nbr, curr_node);

                low[curr_node] = min(low[curr_node], low[nbr]);

                if (low[nbr] > time[curr_node]){
                    res.push_back({curr_node, nbr});
                }
            }
            else if (nbr !=  parent){
                low[curr_node] = min(low[curr_node], low[nbr]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for (auto &e : connections){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        vector<int> time(n, -1), low(n, INT_MAX);
        dfs_traversal(graph, vis, time, low, 0, -1);

        return res;
    }
};