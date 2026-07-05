class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int, int>>> graph(n);
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (auto &e : edges){
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});

            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }

        // making the dist of node to itself 0
        for (int i = 0; i < n; i ++){
            dist[i][i] = 0;
        }

        // trying every node as an intermediate once for every path possible
        for (int k = 0; k < n; k ++){ // intermediate node
            for (int i = 0; i < n; i ++){ // start node
                for (int j = 0; j < n; j ++){ // destination node
                    // path : i -> k -> j

                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX){
                        continue;
                    }

                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // finding the city with min node reachable in threshold
        int reachable = INT_MAX, res_city = -1;
        for (int city = 0; city < n; city ++){
            int cnt = 0;
            for (int i = 0; i < n; i ++){
                if (dist[city][i] <= threshold){
                    cnt ++;
                }
            }

            if (cnt < reachable){
                reachable = cnt;
                res_city = city;
            }
            if (cnt == reachable){
                res_city = city;
            }
        }

        return res_city;
    }
};