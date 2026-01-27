// DIJKSTRA APPROACH : 
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        // Constructing the graph :
        vector<vector<pair<int, int>>> graph(n);
        for (auto &e : edges){
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, 2 * w});
        }

        // Distance Array to stor the minimum possible cost : 
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {Distance to reach this node till now, Node}
        pq.push({0, 0});

        while (!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();

            // If the current node is the dest node : 
            if (u == n - 1){
                return d; // Reached in the min possible cost
            }
            // If the dist to reach the current node is not the latest updated dist : 
            if (d != dist[u]){
                continue;
            }

            // Iterative over all the neighbors : 
            for (auto &[v, wt] : graph[u]){
                if (dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        return -1;
    }
};