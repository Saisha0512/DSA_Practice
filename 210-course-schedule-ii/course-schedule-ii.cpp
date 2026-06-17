class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre_req) {
        // construct a graph
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        for (auto &e : pre_req){
            graph[e[1]].push_back(e[0]);
            indegree[e[0]] ++;
        }

        // starting with the nodes whose indegree == 0
        queue<int> q;
        for (int i = 0; i < n; i ++){
            if (indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> order;
        // bfs loop over queue
        while (!q.empty()){
            int curr_node = q.front();
            q.pop();
            order.push_back(curr_node);

            // iterating over its neighbours & removing the edges connecting them
            for (int nbr : graph[curr_node]){
                indegree[nbr] --;

                // if the indegree becomes 0, then this node should be push as it is the next node in the priority of pre-requisites
                if (indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

        return (order.size() == n)? order : vector<int>();
    }
};