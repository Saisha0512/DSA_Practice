class Solution {
    vector<int> order;
    bool cycle = false;

    void dfs_traversal(vector<vector<int>> &graph, vector<int> &status, int curr_node){
        // visiting the current node
        status[curr_node] = 1;

        // iterating over its neighors
        for (int nbr : graph[curr_node]){
            // node in the current path
            if (status[nbr] == 1){
                cycle = true;
                return;
            }
            else if (status[nbr] == 0){
                dfs_traversal(graph, status, nbr);

                // if cycle was detected
                if (cycle){
                    return;
                }
            }
        }

        // completing the visit of current node
        status[curr_node] = 2;
        order.push_back(curr_node);
    }

public:
    vector<int> findOrder(int n, vector<vector<int>>& pre_req) {
        // constructing the graph
        vector<vector<int>> graph(n);
        for (auto &e : pre_req){
            graph[e[1]].push_back(e[0]);
        }

        vector<int> status(n, 0);
        for (int i = 0; i < n; i ++){
            if (status[i] == 0){
                dfs_traversal(graph, status, i);

                if (cycle){
                    // cycle detected - no order possible
                    return vector<int>();
                }
            }
        }

        // reversing the order to make it correct
        reverse(order.begin(), order.end());
        return (order.size() == n)? order : vector<int>();
    }
};