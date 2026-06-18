class Solution {
    int dfs_traversal(vector<vector<int>> &graph, vector<bool> &vis, int curr_node){
        // visting the current node
        vis[curr_node] = true;

        int curr_cnt = 1;
        // iterating over the neighbors
        for (int nbr : graph[curr_node]){
            if (!vis[nbr]){
                curr_cnt += dfs_traversal(graph, vis, nbr);
            }
        }

        return curr_cnt;
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // constructing the graph
        vector<vector<int>> graph(n);
        for (auto &e : connections){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        // counting the number of disconnected components
        int comp_cnt = 0;
        int edges_needed = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i ++){
            if (!vis[i]){
                int curr_cnt = dfs_traversal(graph, vis, i);
                edges_needed += curr_cnt - 1;
                comp_cnt ++;
            }
        }

        int edges_present = connections.size();
        int extras = edges_present - edges_needed; // extra edges which can be used to connect the components
        return (extras >= comp_cnt - 1)? comp_cnt - 1 : -1;
    }
};