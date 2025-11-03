// DFS Approach : 
class Solution {
    bool dfs(vector<vector<int>> &graph, vector<int> &vis, list<int> &order, int node){
        // Visiting the current node : 
        vis[node] = 1;

        // Iterating over all the neighbours : 
        for (auto nbr : graph[node]){
            if (vis[nbr] == 1){ // nbr is in the current path already - Cycle Detected
                return false;
            }
            if (vis[nbr] == 0){
                if (dfs(graph, vis, order, nbr) == false){
                    return false;
                }
            }
        }

        // After visiting & adding all the neighbours of the current node to the order, 
        // we add the current node to the order list from the front : 
        vis[node] = 2;
        order.push_front(node);
        return true;
    }

public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> graph(n);

        for (auto &p : pre){
            graph[p[1]].push_back(p[0]);
        }

        list<int> order;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i ++){
            if (vis[i] == 0){
                if (dfs(graph, vis, order, i) == false){
                    return vector<int>();
                }
            }
        }

        vector<int> res(order.begin(), order.end());
        return res;
    }
};