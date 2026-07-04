class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto &e : roads){
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        int res = INT_MAX;
        vector<bool> vis(n + 1, false);
        queue<int> q;
        q.push(1); // starting bfs from 1
        vis[1] = true;

        while (!q.empty()){
            int curr_node = q.front();
            q.pop();

            for (auto &[nbr, wt] : graph[curr_node]){
                res = min(res, wt);

                if (!vis[nbr]){
                    q.push(nbr);
                    vis[nbr] = true;
                }
            }
        }

        return res;
    }
};