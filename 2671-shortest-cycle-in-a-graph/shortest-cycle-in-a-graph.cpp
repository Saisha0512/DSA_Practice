class Solution {
    // int res = INT_MAX;

    // void dfs_traversal(vector<vector<int>> &graph, vector<bool> &vis, vector<int> &depth, int curr_node, int parent, int curr_dep){
    //     // visiting the current node
    //     vis[curr_node] = true;
    //     depth[curr_node] = curr_dep;

    //     int tempans = INT_MAX;
    //     // iterating over the neighbors of this current node
    //     for (auto nbr : graph[curr_node]){
    //         if (!vis[nbr]){
    //             dfs_traversal(graph, vis, depth, nbr, curr_node, curr_dep + 1);
    //         }
    //         else if (nbr != parent){ // cycle detected
    //             res = min(res, abs(depth[curr_node] - depth[nbr]) + 1);
    //         }
    //     }
    // }

public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        // creating adjacency list of the graph
        vector<vector<int>> graph(n);
        for (auto &e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]); // undirected edge
        }

        int res = INT_MAX;
        for (int start = 0; start < n; start ++){
            vector<int> parent(n, -1);
            vector<int> dist(n, -1);

            queue<int> q;
            q.push(start);
            dist[start] = 0;

            // bfs loop
            while (!q.empty()){
                int curr_node = q.front();
                q.pop();

                // iterating over the neighbors
                for (int nbr : graph[curr_node]){
                    // unvisited node
                    if (dist[nbr] == -1){
                        dist[nbr] = dist[curr_node] + 1;
                        parent[nbr] = curr_node;
                        q.push(nbr);
                    }
                    // visited node which is not parent
                    else if (parent[nbr] != curr_node && parent[curr_node] != nbr){
                        res = min(res, dist[curr_node] + dist[nbr] + 1);
                    }
                }
            }
        }

        return (res == INT_MAX)? -1 : res;
    }
};