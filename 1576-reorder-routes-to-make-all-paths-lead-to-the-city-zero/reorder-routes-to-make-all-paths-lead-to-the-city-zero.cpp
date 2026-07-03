class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // constructing the graphs
        vector<vector<pair<int, int>>> graph(n);
        for (auto &e : connections){
            graph[e[0]].push_back({e[1], 1}); // a -> b, direction == 1
            graph[e[1]].push_back({e[0], -1}); // a -> b, direction == -1
        }

        // starting bfs from 0th node
        int cnt = 0;
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(0);
        vis[0] = true;
        while (!q.empty()){
            int curr_node = q.front();
            q.pop();

            // iterating over the neighbors 
            for (auto &[nbr, dir] : graph[curr_node]){
                if (!vis[nbr]){
                    if (dir == 1){ // edge : curr_node -> nbr
                        cnt ++;
                    }

                    vis[nbr] = true;
                    q.push(nbr);
                }
            }
        }

        return cnt;
    }
};