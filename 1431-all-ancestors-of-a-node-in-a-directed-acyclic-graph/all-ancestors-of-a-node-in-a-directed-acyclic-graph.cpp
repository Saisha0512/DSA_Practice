class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        for (auto &e : edges){
            graph[e[0]].push_back(e[1]);

            indegree[e[1]] ++;
        }

        queue<int> q;
        for (int i = 0; i < n; i ++){
            if (indegree[i] == 0){
                q.push(i);
            }
        }

        
        vector<unordered_set<int>> anc(n);
        while (!q.empty()){
            auto curr_node = q.front();
            q.pop();

            for (auto nbr : graph[curr_node]){
                // inserting the curr_node & ancestors of curr_node 
                anc[nbr].insert(curr_node);
                for (auto el : anc[curr_node]){
                    anc[nbr].insert(el);
                }

                indegree[nbr] --;
                if (indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

        vector<vector<int>> res(n);
        for (int i = 0; i < n; i ++){
            for (int x : anc[i]){
                res[i].push_back(x);
            }

            sort(res[i].begin(), res[i].end());
        }

        return res;
    }
};