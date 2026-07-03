class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // reversing the edges
        int n = graph.size();
        queue<int> q;
        vector<int> indegree(n, 0);
        vector<vector<int>> rev_graph(n);
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < graph[i].size(); j ++){
                rev_graph[graph[i][j]].push_back(i);
            }

            indegree[i] += graph[i].size();
            if (indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> res;
        while (!q.empty()){
            int curr_node = q.front();
            q.pop();
            res.push_back(curr_node);

            for (int nbr : rev_graph[curr_node]){
                indegree[nbr] --;

                if (indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};