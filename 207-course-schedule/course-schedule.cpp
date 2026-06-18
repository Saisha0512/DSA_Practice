class Solution {
    vector<int> order;

    bool dfs_traversal(vector<vector<int>> &graph, vector<int> &status, int curr_node){
        // visiting the current node
        status[curr_node] = 1;

        // iterating over its neighbors
        for (int nbr : graph[curr_node]){
            if (status[nbr] == 0){
                bool subprob = dfs_traversal(graph, status, nbr);

                if (!subprob){
                    return false;
                }
            }
            else if (status[nbr] == 1){
                // cycle detected
                return false;
            }
        }

        // push the node in the order
        order.push_back(curr_node);
        status[curr_node] = 2;
        return true;
    }

public:
    bool canFinish(int n, vector<vector<int>>& pre_req) {
        // constructing the graph
        vector<vector<int>> graph(n);
        for (auto &e : pre_req){
            graph[e[1]].push_back(e[0]);
        }

        // iterating over the bfs loop
        vector<int> status(n, 0);
        for (int i = 0; i < n; i ++){
            if (status[i] == 0){
                bool subprob = dfs_traversal(graph, status, i);

                if (!subprob){
                    return false;
                }
            }
        }

        return true;
    }
};