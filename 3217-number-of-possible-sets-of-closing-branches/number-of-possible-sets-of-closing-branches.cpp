class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int res = 0;

        for (int mask = 0; mask < (1 << n); mask ++) {
            vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
            
            // adding the edges of the graph
            for (auto &e : roads){
                int u = e[0], v = e[1], w = e[2];
                if ((mask & (1 << u)) && (mask & (1 << v))){
                    dist[u][v] = min(dist[u][v], w);
                    dist[v][u] = min(dist[u][v], w);
                }
            }

            // updating the distance to itself
            for (int i = 0; i < n; i ++){
                dist[i][i] = 0;
            }

            // floyd warshall algo
            for (int k = 0; k < n; k ++){
                for (int i = 0; i < n; i ++){
                    for (int j = 0; j < n; j ++){
                        // i -> k -> j
                        if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX){
                            continue;
                        }

                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }

            // checking for every pair
            bool flag = true;
            for (int i = 0; i < n; i ++){
                for (int j = 0; j < n; j ++){
                    if ((mask & (1 << i)) && (mask & (1 << j))){
                        if (dist[i][j] > maxDistance){
                            flag = false;
                        }
                    }
                }
            }

            if (flag){
                res ++;
            }
        }

        return res;
    }
};