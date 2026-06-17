class Solution {
    bool dfs_traversal(vector<vector<int>> &graph, vector<int> &status, int curr_node){
        // visiting the current node
        status[curr_node] = 1;

        // if the current is a safe node
        // if (graph[curr_node].size() == 0){
        //     return true;
        // }

        // otherwise, iterate over the neighbours
        for (int nbr : graph[curr_node]){
            // cycle detected - not possible to reach safe node
            if (status[nbr] == 1){
                return false;
            }
            else if (status[nbr] == 0){
                bool subprob = dfs_traversal(graph, status, nbr);
                // this traversal can't reach a terminal node
                if (!subprob){
                    return false;
                }
            }
        }

        // all traversals of this node have reached the terminal node
        status[curr_node] = 2;
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> status(n, 0);
        for (int i = 0; i < n; i ++){
            if (status[i] == 0){
                dfs_traversal(graph, status, i);
            }
        }
        
        vector<int> res;
        // storing the nodes that have all traversals reaching a safe node
        for (int i = 0; i < n; i ++){
            if (status[i] == 2){
                res.push_back(i);
            }
        }

        return res;
    }
};