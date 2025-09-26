class Solution {
private : 
    void dfs(int city, vector<vector<int>> &isConn, unordered_set<int> &vis){
        vis.insert(city);

        for (int i = 0; i < isConn[city].size(); i ++){
            if (isConn[city][i] == 1 && vis.find(i) == vis.end()){
                dfs(i, isConn, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConn) {
        int v = isConn.size();
        unordered_set<int> vis;
        int provinces = 0;
        for (int i = 0; i < v; i ++){
            if (vis.find(i) == vis.end()){
                provinces ++;
                dfs(i, isConn, vis);
            }
        }
        return provinces;
    }
};