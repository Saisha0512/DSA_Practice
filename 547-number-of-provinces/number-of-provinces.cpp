class Solution {
    void dfs(int city, vector<vector<int>> &conn, unordered_set<int> &vis){
        vis.insert(city);

        for (int i = 0; i < conn[city].size(); i ++){
            if (conn[city][i] == 1 && vis.find(i) == vis.end()){
                dfs(i, conn, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &conn) {
        int n = conn.size();

        unordered_set<int> vis;
        int cnt = 0;
        for (int i = 0; i < n; i ++){
            if (vis.find(i) == vis.end()){
                cnt ++;
                dfs(i, conn, vis);
            }
        }

        return cnt;
    }
};