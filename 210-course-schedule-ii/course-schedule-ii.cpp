// BFS Approach - Kahn's Algorithm : 
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        // Adjacency List for the graph : 
        for (auto &p : pre){
            graph[p[1]].push_back(p[0]);
            indegree[p[0]] ++;
        }

        // Checking for nodes with indegree = 0 & push them into a queue : 
        queue<int> q;
        for (int i = 0; i < n; i ++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        // BFS Kahn's Algo :
        vector<int> order; 
        while (!q.empty()){
            int node = q.front();
            q.pop();
            order.push_back(node);

            for (auto nbr : graph[node]){
                indegree[nbr] --;
                if (indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

        if (order.size() == n){
            return order;
        }
        return vector<int>();
    }
};