// DFS APPROACH : 
class Solution {
    bool dfs(vector<vector<int>> &graph, int node, vector<int> &state){
        // Visiting the current node : 
        state[node] = 1;

        // Iterating all over the neighbors of the current node : 
        for (auto nbr : graph[node]){
            // Cycle detected : 
            if (state[nbr] == 1){
                return false;
            }

            // If the current nbr is not visited, then we visit it : 
            if (state[nbr] == 0){
                if (!dfs(graph, nbr, state)){
                    return false; // Cycle Detected
                }
            }
        }

        // Marking the current node as visited : 
        state[node] = 2;
        return true;
    }

public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        // Constructing the Adjacency List of the Graph : 
        vector<vector<int>> graph(n);
        for (auto &e : pre){
            int a = e[0], b = e[1];

            graph[b].push_back(a);
        }

        vector<int> state(n, 0);
        for (int i = 0; i < n; i ++){
            if (state[i] == 0){
                if (!dfs(graph, i, state)){
                    return false;
                }
            }
        }

        return true;
    }
};