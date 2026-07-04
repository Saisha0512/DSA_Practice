class Solution {
    const int mod = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto &e : roads){
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; // {dist, node, ways}
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        while (!pq.empty()){
            auto [curr_dist, curr_node] = pq.top();
            pq.pop();
            
            if (curr_dist > dist[curr_node]){
                continue;
            }

            if (curr_node == n - 1){
                continue;
            }

            for (auto &[nbr, wt] : graph[curr_node]){
                long long new_dist = curr_dist + wt;

                if (dist[nbr] > new_dist){
                    dist[nbr] = new_dist;
                    ways[nbr] = ways[curr_node];
                    pq.push({dist[nbr], nbr});
                }
                else if (dist[nbr] == new_dist){
                    ways[nbr] = (ways[nbr] + ways[curr_node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};