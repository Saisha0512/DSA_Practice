class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();
        int m = original.size();

        vector<vector<long long>> dist(26, vector<long long>(26, LLONG_MAX));
        for (int i = 0; i < m; i ++){
            int start = original[i] - 'a', dest = changed[i] - 'a';
            dist[start][dest] = min(dist[start][dest], (long long)cost[i]);
        }
        for (int i = 0; i < 26; i ++){
            dist[i][i] = 0;
        }

        // for every character  we try to reach the target character using all the possible intermediate characters possible
        for (int k = 0; k < 26; k ++){
            for (int i = 0; i < 26; i ++){
                for (int j = 0; j < 26; j ++){
                    // i -> k -> j
                    if (dist[i][k] == LLONG_MAX || dist[k][j] == LLONG_MAX){
                        continue;
                    }

                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        long long total_cost = 0;
        for (int i = 0; i < n; i ++){
            int start = source[i] - 'a', dest = target[i] - 'a';

            if (dist[start][dest] == LLONG_MAX){
                return -1;
            }
            total_cost += dist[start][dest];
        }

        return total_cost;
    }
};