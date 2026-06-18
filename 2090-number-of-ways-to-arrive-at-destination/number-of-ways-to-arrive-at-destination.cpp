class Solution {
    const int mod = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // constructing the graph
        vector<vector<pair<int, int>>> graph(n);
        for (auto &r : roads){
            graph[r[0]].push_back({r[1], r[2]});
            graph[r[1]].push_back({r[0], r[2]});
        }

        vector<long long> ways(n, 0);
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        // bfs loop
        while (!pq.empty()){
            auto [curr_dist, curr_node] = pq.top();
            pq.pop();
            
            // invalid case
            if (curr_dist > dist[curr_node]){
                continue;
            }

            // iterating over the neighbors
            for (auto &[nbr, wt] : graph[curr_node]){
                long long new_dist = curr_dist + wt;
                if (dist[nbr] > new_dist){
                    dist[nbr] = new_dist;
                    ways[nbr] = ways[curr_node];
                    pq.push({dist[nbr], nbr});
                }
                else if (new_dist == dist[nbr]){
                    ways[nbr] = (ways[nbr] + ways[curr_node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};