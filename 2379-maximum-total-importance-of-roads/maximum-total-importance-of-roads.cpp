class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> degree(n, 0);
        for (auto &e : roads){
            degree[e[0]] ++;
            degree[e[1]] ++;
        }
        sort(degree.begin(), degree.end());

        long long total = 0;
        for (int i = 0; i < n; i ++){
            total += ((i + 1) * degree[i]);
        }

        return total;
    }
};