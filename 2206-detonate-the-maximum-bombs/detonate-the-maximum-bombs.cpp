class Solution {
    int dfs_detonate(vector<vector<int>> &bombs, vector<bool> &detonated, int curr_bomb){
        int n = bombs.size();
        // detonating the current bomb
        detonated[curr_bomb] = true; // in process

        int cnt = 1; // for detonating self
        long long x = bombs[curr_bomb][0], y = bombs[curr_bomb][1], r = bombs[curr_bomb][2];
        // iterating over all the possible neighbors
        for (int i = 0; i < n; i ++){
            int a = bombs[i][0], b = bombs[i][1];
            long long dx = (x - a), dy = (y - b);
            long long dist = dx*dx + dy*dy;
            if (!detonated[i] && dist <= r*r*1LL){ // un-detonated bomb
                cnt += dfs_detonate(bombs, detonated, i);
            }
        }

        return cnt;
    }

public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();

        int max_cnt = 0;
        for (int i = 0; i < n; i ++){
            vector<bool> detonated(n, false);
            if (!detonated[i]){
                int curr_cnt = dfs_detonate(bombs, detonated, i);

                max_cnt = max(max_cnt, curr_cnt);
            }
        }

        return max_cnt;
    }
};