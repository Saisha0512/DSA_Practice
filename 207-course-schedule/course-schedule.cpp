// BFS Approach - Kahn's Algorithm : 
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        for(int i = 0; i < pre.size(); i ++){
            int a = pre[i][0], b = pre[i][1];
            graph[b].push_back(a);
            indegree[a] ++;
        }

        queue<int> q;
        for (int i = 0; i < n; i ++){
            if (indegree[i] == 0){
                q.push(i);
            }
        }

        int done = 0;
        while (!q.empty()){
            int curr = q.front();
            q.pop();
            done ++;

            for (int nbr : graph[curr]){
                indegree[nbr] --;
                if (indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

        return (done == n);
    }
};