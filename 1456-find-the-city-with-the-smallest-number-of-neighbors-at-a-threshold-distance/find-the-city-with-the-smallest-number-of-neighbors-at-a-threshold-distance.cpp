class Solution {
    void dijkstra(vector<vector<pair<int, int>>> &graph, vector<int> &res, int src, int threshold, int n){
        int cnt = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {Dist, Node}
        vector<int> dist(n, INT_MAX);
        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty()){
            auto [nodeDist, node] = pq.top();
            pq.pop();

            // Checking if the nodeDistance is more than threshold : 
            if (nodeDist > threshold || nodeDist > dist[node]){
                continue;
            }
            else {
                cnt ++; // src will be counted as extra here, so we would need to subtract 1 in the final ans
            }

            // Iterating over all the nbrs : 
            for (auto &[nbr, wt] : graph[node]){
                // Updating the node's shortest distance only iff the following condition is satisfied : 
                if (dist[nbr] > nodeDist + wt){
                    dist[nbr] = nodeDist + wt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }

        res[src] = cnt - 1; // Updating the resultant vector
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        // Adjacency Graph : 
        vector<vector<pair<int, int>>> graph(n);
        for(auto &edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w}); // Bi - directional
        }

        vector<int> res(n, INT_MAX);
        for (int i = 0; i < n; i ++){
            // Implementing dijkstra for each node as the source & counting the number cities that can be reached upto the threshold distance if started from that particular city : 
            dijkstra(graph, res, i, threshold, n);
        }

        // Iterating over the resultant vector : 
        int minCities = INT_MAX, city = -1;
        for (int i = 0; i < n; i ++){
            if (res[i] <= minCities){
                minCities = res[i];
                city = i;
            }
        }

        return city;
    }
};