class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Adjacency List : 
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < flights.size(); i ++){
            int from = flights[i][0], to = flights[i][1], price = flights[i][2];
            graph[from].push_back({to, price});
        }

        queue<vector<int>> q; // {Node, Price, Stops}
        q.push({src, 0, 0}); // Pushing the source
        vector<int> dist(n, INT_MAX); // To store the cheapest price for every node
        dist[src] = 0;
        while (!q.empty()){
            auto curr = q.front();
            q.pop();
            int node = curr[0], nodePrice = curr[1], nodeStops = curr[2];

            if (nodeStops > k){
                continue;
            }

            for (auto [nbr, wt] : graph[node]){
                // Updating the nbr only if the price in the current price is cheaper & the stops in the current path <= k : 
                if (dist[nbr] > nodePrice + wt && nodeStops <= k){
                    dist[nbr] = nodePrice + wt; // Updating the distance vector
                    q.push({nbr, dist[nbr], nodeStops + 1}); // Pushing nbr, new price & new no of stops into the queue
                }
            }
        }

        if (dist[dst] == INT_MAX){
            return -1; // No possible route 
        }
        return dist[dst];
    }
};