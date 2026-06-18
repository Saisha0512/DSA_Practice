class Solution {
    int dijkstra(vector<vector<pair<int, int>>> &graph, int n, int curr_node, int threshold){
        // implementing dijkstra bfs loop starting from curr_node
        vector<int> dist(n, INT_MAX);
        queue<int> q;
        q.push(curr_node);
        dist[curr_node] = 0;

        // bfs loop
        while (!q.empty()){
            int node = q.front();
            q.pop();

            // if the dist exced the threshold
            if (dist[node] > threshold){
                continue;
            }

            // iterating over the neighbors
            for (auto &[nbr, wt] : graph[node]){
                int new_dist = dist[node] + wt;
                if (new_dist < dist[nbr]){
                    dist[nbr] = new_dist;
                    q.push(nbr);
                }
            }
        }

        // counting the no of nodes within the threshold
        int cnt = 0;
        for (int i = 0; i < n; i ++){
            if (dist[i] <= threshold){
                cnt ++;
            }
        }

        return cnt - 1; // avoid counting the curr_node itself
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        // construcitng the adjacency list of the graph
        vector<vector<pair<int, int>>> graph(n);
        for (auto &e : edges){
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        int max_reachable = INT_MAX, city = 0;
        for (int i = 0; i < n; i ++){
            int reachable_cities = dijkstra(graph, n, i, threshold);
            
            if (reachable_cities < max_reachable){
                max_reachable = reachable_cities;
                city = i;
            }
            else if (reachable_cities == max_reachable){
                city = i;
            }
        }

        return city;
    }
};