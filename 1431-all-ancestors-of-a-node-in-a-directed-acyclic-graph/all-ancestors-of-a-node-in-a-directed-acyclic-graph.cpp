class Solution {
    vector<bool> vis;
    vector<vector<int>> res;

    vector<int> dfs_traversal(vector<vector<int>> &graph, int curr){
        // base case
        if (vis[curr]){
            return res[curr];
        }

        unordered_set<int> ancestors;
        // iterating over all the neighbours
        for (int nbr : graph[curr]){
            vector<int> temp = dfs_traversal(graph, nbr); // ancestors of nbr
            ancestors.insert(nbr);

            // all the ancestors of nbr will also be the ancestors of curr
            for (int x : temp){
                ancestors.insert(x);
            }
        }

        res[curr] = vector<int>(ancestors.begin(), ancestors.end());
        sort(res[curr].begin(), res[curr].end());
        // completely visited the current node
        vis[curr] = true;

        return res[curr];
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // constructing a reversed graph
        vector<vector<int>> graph(n);
        for (auto &e : edges){
            graph[e[1]].push_back(e[0]);
        }

        vis.resize(n, false);
        res.resize(n);

        // traversing every node to get its ancestors
        for (int i = 0; i < n; i ++){
            if (!vis[i]){
                dfs_traversal(graph, i);
            }
        }

        return res;
    }
};