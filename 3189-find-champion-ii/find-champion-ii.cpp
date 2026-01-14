class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for (auto &e : edges){
            int u = e[0], v = e[1];
            indegree[v] ++;
        }

        int ans = -1;
        for (int i = 0; i < n; i ++){
            if (indegree[i] == 0){
                if (ans != -1){
                    return -1;
                }
                else {
                    ans = i;
                }
            }
        }

        return ans;
    }
};