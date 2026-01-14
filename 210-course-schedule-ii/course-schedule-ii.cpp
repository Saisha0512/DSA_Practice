// BFS APPROACH (Kahn's Algo - Indegree) : 
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        // Constructing the graph : 
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n);
        for (auto &p : pre){
            int a = p[0], b = p[1];
            graph[b].push_back(a);
            indegree[a] ++;
        }

        vector<int> order;
        queue<int> q;
        // Checking for nodes with indegree = 0 : 
        for (int i = 0; i < n; i ++){
            if (indegree[i] == 0){
                q.push(i);
            }
        }

        while (!q.empty()){
            int curr = q.front();
            q.pop();

            order.push_back(curr);
            for (auto nbr : graph[curr]){
                indegree[nbr] --;

                if (indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

        if (order.size() != n){
            return {};
        }

        return order;
    }
};