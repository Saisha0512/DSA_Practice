// BFS APPROACH : 
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        // Constructing the graph : 
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n);
        for (auto &p : pre){
            int a = p[0], b = p[1];

            graph[b].push_back(a); // Directed graph
            indegree[a] ++;
        }

        queue<int> q;
        // Checking for the node with indegree = 0
        for (int i = 0; i < n; i ++){
            if (indegree[i] == 0){
                q.push(i);
            }
        }

        // Iterating over the queue :
        int cnt = 0; // To maintain the count of the courses that are completed
        while (!q.empty()){
            int curr = q.front();
            q.pop();
            cnt ++;

            for (int nbr : graph[curr]){
                indegree[nbr] --;

                if (indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

        return (cnt == n);
    }
};