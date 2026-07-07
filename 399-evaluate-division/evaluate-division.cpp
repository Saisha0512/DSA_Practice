class Solution {
    double dfs_traversal(unordered_map<string, vector<pair<string, double>>> &graph, unordered_set<string> &vis, string curr_node, string parent, string dest, double curr_prod){
        if (curr_node == dest){
            return curr_prod;
        }
        vis.insert(curr_node);

        // iterating over the neighbors
        for (auto &[nbr, wt] : graph[curr_node]){
            if (!vis.count(nbr)){
                double subprob = dfs_traversal(graph, vis, nbr, curr_node, dest, curr_prod * wt);

                if (subprob != -1){
                    return subprob;
                }
            }
            else {
                continue;
            }
        }

        vis.erase(curr_node);
        return -1;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        unordered_map<string, vector<pair<string, double>>> graph;
        int n = equations.size();
        for (int i = 0; i < n; i ++){
            string x = equations[i][0], y = equations[i][1];
            // x -> y == x/y
            graph[x].push_back({y, values[i]});
            graph[y].push_back({x, 1 / values[i]});
        }

        int q = queries.size();
        vector<double> res;
        for (int i = 0; i < q; i ++){
            string c = queries[i][0], d = queries[i][1];

            if (!graph.count(c) || !graph.count(d)){
                res.push_back(-1);
                continue;
            }
            if (c == d){
                res.push_back(1);
                continue;
            }

            unordered_set<string> vis;
            double prod = dfs_traversal(graph, vis, c, "", d, 1);
            res.push_back(prod);
        }

        return res;
    }
};