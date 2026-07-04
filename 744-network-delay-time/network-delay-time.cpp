class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto &e : times){
            graph[e[0]].push_back({e[1], e[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap
        pq.push({k, 0});
        dist[k] = 0;

        while (!pq.empty()){
            auto [curr_node, time] = pq.top();
            pq.pop();

            if (time > dist[curr_node]){
                continue;
            }

            for (auto &[nbr, wt] : graph[curr_node]){
                if (dist[nbr] > time + wt){
                    dist[nbr] = time + wt;
                    pq.push({nbr, dist[nbr]});
                }
            }
        }

        int min_time = INT_MIN;
        for (int i = 1; i <= n; i ++){
            if (dist[i] == INT_MAX){
                // unreachable node
                return -1;
            }

            min_time = max(min_time, dist[i]);
        }

        return min_time;
    }
};