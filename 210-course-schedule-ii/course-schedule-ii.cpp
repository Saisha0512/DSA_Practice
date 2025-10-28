class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        int m = pre.size();

        // Setting up the indegree & the graph vector : 
        vector<vector<int>> graph(n);
        vector<int> indegree(n);
        for (auto &p : pre){
            graph[p[1]].push_back(p[0]);
            indegree[p[0]] ++;
        }

        queue<int> q;
        // Searching for the nodes with indegree = 0 : 
        for (int i = 0; i < n; i ++){
            if (indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> order;
        // Traversing throughout the graph, starting from the nodes with indegree = 0 : 
        while (!q.empty()){
            auto curr = q.front();
            q.pop();
            order.push_back(curr);

            for (int nbr : graph[curr]){
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