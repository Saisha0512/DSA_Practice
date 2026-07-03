class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n);
        for (auto &p : prerequisites){
            graph[p[1]].push_back(p[0]);
            indegree[p[0]] ++;
        }

        queue<int> q;
        for (int i = 0; i < n; i ++){
            if (indegree[i] == 0){
                q.push(i);
            }
        }

        // kahn's algo
        vector<int> order;
        while (!q.empty()){
            int curr_node = q.front();
            q.pop();
            order.push_back(curr_node);

            for (int nbr : graph[curr_node]){
                indegree[nbr] --;

                if (indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

        return (order.size() == n)? order : vector<int>();
    }
};