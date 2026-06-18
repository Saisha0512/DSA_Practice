class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // constructing the graph
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto &e : times){
            graph[e[0]].push_back({e[1], e[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        queue<int> q;
        q.push(k);
        dist[k] = 0;

        while (!q.empty()){
            int curr_node = q.front();
            q.pop();

            // iterating over the neighbours of this node
            for (auto &[nbr, wt] : graph[curr_node]){
                int curr_time = dist[curr_node] + wt;
                if (dist[nbr] > curr_time){
                    dist[nbr] = curr_time;
                    q.push(nbr);
                }
            }
        }

        int max_time = INT_MIN;
        for (int i = 1; i <= n; i ++){
            if (dist[i] == INT_MAX){ // unreachable node
                return -1;
            }
            max_time = max(max_time, dist[i]);
        }

        return max_time;
    }
};