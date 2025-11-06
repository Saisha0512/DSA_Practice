class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        // Adjacency List : 
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto &time : times){
            int u = time[0], v = time[1], w = time[2];
            graph[u].push_back({v, w});
        }

        // Min - Heap for Dijkstra : 
        vector<int> signal(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {Dist, Node}
        signal[src] = 0;
        pq.push({0, src});

        while (!pq.empty()){
            auto [nodeDist, node] = pq.top();
            pq.pop();

            if (nodeDist != signal[node]){
                continue; // The iteration for the smallest distance is already done earlier.
            }

            // Iterating over the current node's neighbours : 
            for (auto &[nbr, wt] : graph[node]){
                // Updating the distance of the nbr only if the below condition is satisfied : 
                if (signal[nbr] > nodeDist + wt){
                    signal[nbr] = nodeDist + wt;
                    pq.push({signal[nbr], nbr});
                }
            }
        }

        // Checking if all the nodes receive the signal & finding out the minimum time it takes for all n nodes to receive the signal : 
        int time = 0;
        for (int i = 1; i <= n; i ++){
            if (signal[i] == INT_MAX){
                return -1;
            }
            time = max(time, signal[i]);
        }

        return time;
    }
};