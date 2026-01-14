// DFS APPROACH : 
class Solution {
    vector<int> order;
    bool cycle = false;

private : 
    void dfs(vector<vector<int>> &graph, int node, vector<int> &status){
        // Visiting the current node : 
        status[node] = 1;

        // Iterating over all the nbrs : 
        for (auto nbr : graph[node]){
            if (status[nbr] == 0){
                dfs(graph, nbr, status);
                if (cycle){
                    return;
                }
            }
            else if (status[nbr] == 1){
                cycle = true;
                return;
            }
        }

        // Pushing the current node into the order after visiting all the neighbours : 
        status[node] = 2; // Visited
        order.push_back(node);
    }

public :
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        // Constructing the graph : 
        vector<vector<int>> graph(n);
        for (auto &p : pre){
            int a = p[0], b = p[1];
            graph[b].push_back(a);
        }

        vector<int> status(n, 0);
        for (int i = 0; i < n; i ++){
            if (status[i] == 0){
                dfs(graph, i, status);
                if (cycle){
                    return {};
                }
            }
        }

        if (order.size() != n || cycle){
            return {};
        }

        reverse(order.begin(), order.end());
        return order;
    }
};