class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9 + 7;
        // Adjacency List of the graph : 
        vector<vector<pair<int, int>>> graph(n);
        for (auto &path : roads){
            int u = path[0], v = path[1], t = path[2];
            graph[u].push_back({v, t});
            graph[v].push_back({u, t});
        }

        vector<long long> ways(n, 0); // To store the no of ways for each node
        vector<long long> time(n, LLONG_MAX); // To store minimum dist for each node
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; // Min - Heap
        time[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        // Iterating over the priority queue : 
        while (!pq.empty()){
            auto [nodeTime, node] = pq.top();
            pq.pop();

            if (nodeTime > time[node]){ // If the current nodeTime is greater than the minimum time encountered till now, then we just ignore it
                continue;
            }

            // Iterating over the neighbours of the current node : 
            for (auto &[nbr, wt] : graph[node]){
                long long newTime = nodeTime + wt;
                // If the current time is equal to the minimum time encountered till now : 
                if (newTime == time[nbr]){
                    ways[nbr] = (ways[nbr] + ways[node]) % mod;
                }

                // If we find a new minimum time to reach this nbr : 
                if (newTime < time[nbr]){
                    time[nbr] = newTime;
                    ways[nbr] = ways[node];
                    pq.push({time[nbr], nbr});
                }
            }
        }

        return ways[n - 1];
    }
};