class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int n = source.size();
        unordered_map<string, int> str;
        int idcnt = 0;

        // Mapping strings to unique IDs : 
        for (string &s : original){
            if (str.find(s) == str.end()){
                str[s] = idcnt ++;
            }
        }
        for (string &s : changed){
            if (str.find(s) == str.end()){
                str[s] = idcnt ++;
            }
        }

        vector<vector<long long>> dist(idcnt, vector<long long> (idcnt, LLONG_MAX));
        for (int i = 0; i < idcnt; i ++){
            dist[i][i] = 0;
        }

        // Direct Transformation : 
        for (int i = 0; i < original.size(); i ++){
            int u = str[original[i]];
            int v = str[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Floyd - Warshall : 
        for (int k = 0; k < idcnt; k ++){
            for (int i = 0; i < idcnt; i ++){
                for (int j = 0; j < idcnt; j ++){
                    if (dist[i][k] < LLONG_MAX && dist[k][j] < LLONG_MAX){
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0;
        vector<int> len;
        for (string &s : original){
            len.push_back(s.size());
        }
        sort(len.begin(), len.end());
        len.erase(unique(len.begin(), len.end()), len.end());

        for (int i = 0; i < n; i ++){
            if (dp[i] == LLONG_MAX){
                continue;
            }

            // Matching single character : 
            if (source[i] == target[i]){
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            // Trying substring transformations : 
            for (int l : len){
                if (i + l > n){
                    break;
                }

                string s = source.substr(i, l);
                string t = target.substr(i, l);

                if (s == t){
                    dp[i + l] = min(dp[i + l], dp[i]);
                }

                if (str.find(s) != str.end() && str.find(t) != str.end()){
                    int u = str[s];
                    int v = str[t];
                    if (dist[u][v] < LLONG_MAX){
                        dp[i + l] = min(dp[i + l], dp[i] + dist[u][v]);
                    }
                }
            }
        }
        

        return ((dp[n] >= LLONG_MAX)? -1 : dp[n]);
    }
};