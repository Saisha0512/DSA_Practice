class Solution {
    bool cycle = false;
    vector<int> order;

    void dfs_traversal(vector<vector<int>> &graph, vector<int> &status, int curr_node){
        if (cycle){
            return;
        }

        status[curr_node] = 1;

        for (int nbr : graph[curr_node]){
            if (status[nbr] == 0){
                dfs_traversal(graph, status, nbr);
            }
            else if (status[nbr] == 1){
                cycle = true;
                return; // cycle detected
            }
        }

        status[curr_node] = 2;
        order.push_back(curr_node);
    }

public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n);
        for (auto &p : prerequisites){
            graph[p[1]].push_back(p[0]);
        }

        vector<int> status(n, 0);
        for (int i = 0; i < n; i ++){
            if (!status[i]){
                dfs_traversal(graph, status, i);

                if (cycle){
                    return vector<int>();
                }
            }
        }

        reverse(order.begin(), order.end());
        return (order.size() == n)? order : vector<int>();
    }
};