class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n);
        for (auto &e : pre){
            graph[e[1]].push_back(e[0]);
            indegree[e[0]] ++;
        }

        queue<int> q;
        for (int i = 0; i < n; i ++){
            if (!indegree[i]){
                q.push(i);
            }
        }

        int cnt = 0;
        while (!q.empty()){
            int curr_node = q.front();
            q.pop();
            cnt ++;

            for (int nbr : graph[curr_node]){
                indegree[nbr] --;

                if (indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

        return (cnt == n);
    }
};