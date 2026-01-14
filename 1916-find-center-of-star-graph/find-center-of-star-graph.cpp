class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = INT_MIN;
        // Counting the degrees for each node :  
        unordered_map<int, int> degree;
        for (auto &e : edges){
            int a = e[0], b = e[1];
            degree[a] ++;
            degree[b] ++;
            n = max(n, max(a, b));
        }

        for (auto &p : degree){
            if (p.second == n - 1){
                return p.first;
            }
        }

        return -1;
    }
};