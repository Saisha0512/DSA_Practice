class Solution {
    vector<vector<int>> res;
    vector<bool> vis;

    vector<int> dfs_traversal(vector<vector<int>> &graph, int curr){
        // checking 
        if (vis[curr]){
            return res[curr];
        }

        unordered_set<int> ancestors;
        
        // we need to add all of its neighbours & nodes that can be reached if we start from the curr node
        for (int nbr : graph[curr]){
            vector<int> temp = dfs_traversal(graph, nbr); // it contains the nodes that can be reached from the node nbr
            ancestors.insert(nbr);
            
            for (int x : temp){
                ancestors.insert(x);
            }
        }

        res[curr] = vector<int>(ancestors.begin(), ancestors.end());
        sort(res[curr].begin(), res[curr].end());
        vis[curr] = true;
        return res[curr];
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // constructing the graph, by reversing each edge
        vector<vector<int>> graph(n);
        for (auto &e : edges){
            graph[e[1]].push_back(e[0]);
        }

        // running dfs for each node & adding all the nodes that could be reached via it
        res.resize(n);
        vis.resize(n, false);
        // iterating over all the elements
        for (int i = 0; i < n; i ++){
            dfs_traversal(graph, i);
        }

        return res;
    }
};