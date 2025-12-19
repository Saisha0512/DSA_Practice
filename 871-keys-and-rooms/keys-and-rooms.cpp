class Solution {
    void dfs(vector<vector<int>> &rooms, vector<bool> &vis, int node){
        // Visiting the current room : 
        vis[node] = true;

        // Iterating over the rooms whose keys are found in this room & visiting them : 
        for (auto nbr : rooms[node]){
            if (!vis[nbr]){
                dfs(rooms, vis, nbr); 
            }
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);

        dfs(rooms, vis, 0);
        
        // Checking if any room is unvisited : 
        for (auto x : vis){
            if (!x){
                return false;
            }
        }

        return true;
    }
};