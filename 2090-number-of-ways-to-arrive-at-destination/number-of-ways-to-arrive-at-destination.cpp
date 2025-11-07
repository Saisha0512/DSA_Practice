class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;
        // Adjacency List : 
        vector<vector<pair<int, int>>> graph(n);
        for (auto &way : roads){
            int u = way[0], v = way[1], w = way[2];
            graph[u].push_back({v, w}); // {nbr, wt}
            graph[v].push_back({u, w});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; // {Dist, Node} - Min Heap
        vector<int> ways(n, 0); // To store the no of ways to reach that node
        vector<long long> dist(n, LLONG_MAX); // To store the minimum distance

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0}); // Pushing the source node

        while (!pq.empty()){
            auto [nodeDist, node] = pq.top();
            pq.pop();

            if (nodeDist > dist[node]){
                continue;
            }

            // Iterating over the neighbours : 
            for (auto &[nbr, wt] : graph[node]){
                // Updating the dist(time taken to travel till that intersection) iff the following is satisfied : 
                if (dist[nbr] > nodeDist + wt){
                    dist[nbr] = nodeDist + wt;
                    ways[nbr] = ways[node];
                    pq.push({dist[nbr], nbr});
                }
                else if (dist[nbr] == nodeDist + wt){
                    ways[nbr] = (ways[nbr] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};