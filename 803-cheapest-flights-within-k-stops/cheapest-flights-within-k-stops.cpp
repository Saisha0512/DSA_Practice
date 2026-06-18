class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // constructing the adjacency list of the graph
        vector<vector<pair<int, int>>> graph(n);
        for (auto fl : flights){
            int from = fl[0], to = fl[1], price = fl[2];
            graph[from].push_back({to, price});
        }

        queue<vector<int>> q; // {nodes, price, stops}
        q.push({src, 0, 0});
        vector<int> dist(n, INT_MAX); // to store the cheapest price to reach every node
        dist[src] = 0;

        // bfs loop
        while (!q.empty()){
            auto curr = q.front();
            q.pop();
            int curr_node = curr[0], price = curr[1], stops = curr[2];

            // if the stops is more than the limit
            if (stops > k){
                continue;
            }

            // updating the neighbors
            for (auto &[nbr, wt] : graph[curr_node]){
                if (stops <= k && dist[nbr] > price + wt){
                    dist[nbr] = price + wt;
                    q.push({nbr, dist[nbr], stops + 1});
                }
            }
        }

        if (dist[dst] == INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};