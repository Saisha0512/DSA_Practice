class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre_req) {
        // constructing the graph
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n);
        for (auto &e : pre_req){
            graph[e[1]].push_back(e[0]);
            indegree[e[0]] ++;
        }

        // bfs approach
        // pushing all the nodes with indegree 0 to the queue
        queue<int> q;
        for (int i = 0; i < n; i ++){
            if (indegree[i] == 0){
                q.push(i);
            }
        }

        // bfs loop
        vector<int> order;
        while (!q.empty()){
            int curr_node = q.front();
            q.pop();

            // pushing this node in the order
            order.push_back(curr_node);

            // iterating over its nieghbors & removing all its outgoing edges
            for (int nbr : graph[curr_node]){
                indegree[nbr] --;

                if (indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

        return (order.size() == n);
    }
};